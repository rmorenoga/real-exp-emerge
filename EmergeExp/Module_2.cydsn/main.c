#include <project.h>
#include <..\lib\CPG.h>
#include <..\lib\CANProtocol.h>
#include <..\lib\Hormone.h>
#include <..\lib\AX12.h>

#define CAN_RX_MAILBOX_0_SHIFT      (1u)
#define CAN_RX_MAILBOX_1_SHIFT      (2u)
#define MOTOR_ID                    (1)

/* Reset received mailbox number define */
#define RX_MAILBOX_RESET 			(0xFFu)

/* Global variables*/
//Declared in each library for ease of implementation
//TODO: Reorganize global variables in main
    float angle = 0.0;
    int motorGoal;
    uint8 controlFlags = 0x00u; //Flags: bit0(0x01):SendHormone bit1(0x02):N/A bit2(0x04):N/A bit3(0x08):N/A
                        //Flags: bit4(0x10):N/A         bit5(0x20):N/A bit6(0x40):N/A bit7(0x80):N/A
    uint8 horm[6];
    
//uint8 receiveMailboxNumber = RX_MAILBOX_RESET; // Global variable used to store receive message mailbox number

/*Function Prototypes*/
CY_ISR_PROTO(ISR_CAN); // CAN Interruption handler declaration
int convertAngleToPosition(float input, int maxPos, int minPos);


int main()
{      
    /*Initialization Routines*/
    //Init LED's
    LED_1_Write(0);
	//LED_2_Write(0);
	//LED_3_Write(0);
	//LED_4_Write(0);
    
    //Motor communication
    //RX_Start();                     //rx motor
    //MOTOR_Start();                  //tx motor
 
    CAN_Start(); //  Start CAN module
    
    //SENSOR_1_Start();               // Start sensor I2C
	//SENSOR_1_Enable();
	//SENSOR_2_Start();
	//SENSOR_2_Enable();
	//SENSOR_3_Start();
	//SENSOR_3_Enable();
	//SENSOR_4_Start();
	//SENSOR_4_Enable();
    
    //CyIntSetVector(CAN_ISR_NUMBER, ISR_CAN); // Set CAN interrupt handler to local routine
    CAN_isr_StartEx(ISR_CAN);       // Equivalent to last instruction 
    
    CyGlobalIntEnable;              // Enable global interrupts
    //CAN_GlobalIntEnable();        // Equivalent to last instruction
    
    CyDelay(100);
    
	//initVCNL_1();                   // Check sensors working (Enable global interrupts before this)
	//initVCNL_2();
	//initVCNL_3();
	//initVCNL_4();
    
                  

    /*Loop Forever*/
    for(;;){
        
        //Read and clear phase and hormone buffers
        
        if(((receivedFlags >> 0) & 1u) != 0u){
            receivePhase(CAN_RX_MAILBOX_phaseData0, teta);
            receivedFlags &= ~(1u << 0);
        }
            
            //readHormoneBuffers();
            
        
        //Sense environment
            //Clear SendHormone flag
            //controlFlags &= ~(0x01u);// clear a bit with: number &= ~(1u << n);
            //Read Sensors and create hormone
        //generateHormone(&controlFlags,horm);
        
        
        
        //CPG and movement
        updateCPG(teta);            // Update CPG Equations
        angle = (offset+(cos(teta[0])*ampli)); // Calculate motor position change to output a number between 0 and 1
        motorGoal = convertAngleToPosition(angle,800,200);                                    
        //MoveSpeed(MOTOR_ID, motorGoal, 150);
        
        //Send phase message
        //sendPhase(teta[0]);         // Send phase through CAN
        
        //Send Generated Hormone message
        //if ((controlFlags & 0x01u) != 0u){
            sendHormone();
       // }
        
        //Propagate received hormone message
        
        //LED_1_Write(1);
        //CyDelay(500);
        //LED_1_Write(0);
        
        CyDelay(4000);              // Wait for 1 second and repeat
    }
}

CY_ISR(ISR_CAN){
               
    /* Clear Receive Message flag */
    CAN_INT_SR_REG = CAN_RX_MESSAGE_MASK; //Doesn't acknowledge message
    //CAN_MsgRXIsr();     //Be careful acknowledges message before receiving mailbox can be sorted out
    
    LED_1_Write(1);
    CyDelay(10);
    LED_1_Write(0);
    //Identify message header (see isr example)
    //If phase data
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_0_SHIFT) != 0u){
        receivedFlags |= 1u; // Set phase1 received flag
        //receivePhase(CAN_RX_MAILBOX_phaseData0); // Deprecated:Receive phase information and store in buffer  
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_phaseData0); //Message acknowledge, strange behavior when trying to sort out receiving mailbox after this
    }
    
    
    //If Hormone Data
    /* if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_1_SHIFT) != 0u){
        receiveHormone(CAN_RX_MAILBOX_hormoneData0);     // Receive hormone information and updtates appropiate buffer
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData0);
    }*/
        //Identify Sender
        //Transform data (rearrange)
        //Store in sender buffer
            //If sender buffer full
                //Discard message
        //Add to filtered value

}

int convertAngleToPosition(float input, int maxPos, int minPos){
    
    int output = 0;
    const float oldRange = M_PI/2-(-M_PI/2);
    float newRange = maxPos - minPos;
    float convertedInput =  (((input - (-M_PI/2)) * newRange) / oldRange) + minPos;
    
    output = convertedInput;
    
    return output;    
}
