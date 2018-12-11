#include <project.h>
//#include <stdlib.h>
#include <..\lib\CPG.h>
#include <..\lib\CANProtocol.h>
#include <..\lib\Hormone.h>
#include <..\lib\AX12.h>
#include <..\lib\SpTransform.h>
#include <..\lib\Propagate.h>


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
    uint8 horm[HORM_SIZE];
    int8 ori = 2;
    
//uint8 receiveMailboxNumber = RX_MAILBOX_RESET; // Global variable used to store receive message mailbox number

/*Function Prototypes*/
CY_ISR_PROTO(ISR_CAN); // CAN Interruption handler declaration
int convertAngleToPosition(float input, int maxPos, int minPos);
//float randd(void);
void receive(void);


int main()
{      
    /*Initialization Routines*/
    //Init LED's
    LED_1_Write(0);
	LED_2_Write(0);
	LED_3_Write(0);
	LED_4_Write(0);
    
    //Motor communication
    RX_Start();                     //rx motor
    MOTOR_Start();                  //tx motor
 
    CAN_Start(); //  Start CAN module
    
    SENSOR_1_Start();               // Start sensor I2C (Start calls enable)
	//SENSOR_1_Enable();
	SENSOR_2_Start();
	//SENSOR_2_Enable();
	SENSOR_3_Start();
	//SENSOR_3_Enable();
	SENSOR_4_Start();
	//SENSOR_4_Enable();
    
    
    configureCANID();
    //CyIntSetVector(CAN_ISR_NUMBER, ISR_CAN); // Set CAN interrupt handler to local routine
    CAN_isr_StartEx(ISR_CAN);       // Equivalent to last instruction 
    
    CyGlobalIntEnable;              // Enable global interrupts
    //CAN_GlobalIntEnable();        // Equivalent to last instruction
    
    CyDelay(100);
    
	initVCNL_1();                   // Check sensors working (Enable global interrupts before this!)
	initVCNL_2();
	initVCNL_3();
	initVCNL_4();
    
                  

    /*Loop Forever*/
    for(;;){
        
        //Read and clear phase and hormone buffers
        receive();            
        
        //Sense environment
            //Clear SendHormone flag
            controlFlags &= ~(0x01u);// clear a bit with: number &= ~(1u << n);
            //Read Sensors and create hormone
            generateHormone(&controlFlags,horm);
        
        spTransformAllBuffers();
        
        receptors(horm,ori);
        
        
        //CPG and movement
        updateCPG(teta);            // Update CPG Equations
        angle = (offset+(cos(teta[0])*ampli)); // Calculate motor position change to output a number between 0 and 1
        motorGoal = convertAngleToPosition(angle,600,400); //800,200                                    
        MoveSpeed(MOTOR_ID, motorGoal, 150);
        
        //Send phase message
        sendPhase(teta[0]);         // Send phase through CAN
        
        //LED_1_Write(1);
        //CyDelay(10);
        //LED_1_Write(0);
        //Send Generated Hormone message
        if ((controlFlags & 0x01u) != 0u){
            uint8 mask = createMaskAll();
            sendHormone(horm,mask);
        }
        
        //Propagate received hormone message
        propagate();
        
        //LED_1_Write(1);
        //CyDelay(500);
        //LED_1_Write(0);
        
        CyDelay(10);              // Wait for 1 second and repeat
    }
}

CY_ISR(ISR_CAN){
               
    /* Clear Receive Message flag */
    CAN_INT_SR_REG = CAN_RX_MESSAGE_MASK; //Doesn't acknowledge message
    //CAN_MsgRXIsr();     //Be careful acknowledges message before receiving mailbox can be sorted out
    
    LED_1_Write(1);
    //CyDelay((int)(randd()*30));
    CyDelay(10);
    LED_1_Write(0);
    //Identify message header (see isr example)
    //If phase data
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_0_SHIFT) != 0u){
        receivedFlags |= (1u << 0); // Set phase1 received flag
        //receivePhase(CAN_RX_MAILBOX_phaseData0); // Deprecated:Receive phase information and store in buffer  
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_phaseData0); //Message acknowledge, strange behavior when trying to sort out receiving mailbox after this
    }
    
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_1_SHIFT) != 0u){
        receivedFlags |= (1u << 1); // Set phase1 received flag
        //receivePhase(CAN_RX_MAILBOX_phaseData0); // Deprecated:Receive phase information and store in buffer  
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_phaseData1); //Message acknowledge, strange behavior when trying to sort out receiving mailbox after this
    }
    
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_2_SHIFT) != 0u){
        receivedFlags |= (1u << 2); // Set phase1 received flag
        //receivePhase(CAN_RX_MAILBOX_phaseData0); // Deprecated:Receive phase information and store in buffer  
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_phaseData2); //Message acknowledge, strange behavior when trying to sort out receiving mailbox after this
    }
    
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_3_SHIFT) != 0u){
        receivedFlags |= (1u << 3); // Set phase1 received flag
        //receivePhase(CAN_RX_MAILBOX_phaseData0); // Deprecated:Receive phase information and store in buffer  
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_orientationData); //Message acknowledge, strange behavior when trying to sort out receiving mailbox after this
    }
    
    //If Hormone Data
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_4_SHIFT) != 0u){
        receivedFlags |= (1u << 4);
        //receiveHormone(CAN_RX_MAILBOX_hormoneData0);     // Receive hormone information and updtates appropiate buffer
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData00);
        //CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData01);
        //CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData02);
    }
    
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_7_SHIFT) != 0u){
        receivedFlags |= (1u << 5);
        //receiveHormone(CAN_RX_MAILBOX_hormoneData0);     // Receive hormone information and updtates appropiate buffer
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData10);
        //CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData01);
        //CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData02);
    }
    
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_10_SHIFT) != 0u){
        receivedFlags |= (1u << 6);
        //receiveHormone(CAN_RX_MAILBOX_hormoneData0);     // Receive hormone information and updtates appropiate buffer
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData20);
        //CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData01);
        //CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData02);
    }
    
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_13_SHIFT) != 0u){
        receivedFlags |= (1u << 7);
        //receiveHormone(CAN_RX_MAILBOX_hormoneData0);     // Receive hormone information and updtates appropiate buffer
        CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData30);
        //CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData01);
        //CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData02);
    }
    

}

int convertAngleToPosition(float input, int maxPos, int minPos){
    
    int output = 0;
    const float oldRange = 2-(-2);
    float newRange = maxPos - minPos;
    float convertedInput =  (((input - (-2)) * newRange) / oldRange) + minPos;
    
    output = convertedInput;
    
    return output;    
}

//float randd(){
  //  return (float)rand()/((float)RAND_MAX+1);   
//}

void receive(void){
    
    buffercount[0]=0;
    if(((receivedFlags >> 0) & 1u) != 0u){
        receivePhase(CAN_RX_MAILBOX_phaseData0, teta);
        receivedFlags &= ~(1u << 0);
    }
    
    buffercount[1]=0;
    if(((receivedFlags >> 1) & 1u) != 0u){
        receivePhase(CAN_RX_MAILBOX_phaseData1, teta);
        receivedFlags &= ~(1u << 1);
    }
    
    buffercount[2]=0;
    if(((receivedFlags >> 2) & 1u) != 0u){
        receivePhase(CAN_RX_MAILBOX_phaseData2, teta);
        receivedFlags &= ~(1u << 2);
    }
    
    #ifdef MODULE_T
        buffercount[3]=0;
        if(((receivedFlags >> 3) & 1u) != 0u){
            receivePhase(CAN_RX_MAILBOX_phaseData3, teta);
            receivedFlags &= ~(1u << 3);
        }
    #else    
        if(((receivedFlags >> 3) & 1u) != 0u){
           ori = receiveOri(CAN_RX_MAILBOX_orientationData);
           receivedFlags &= ~(1u << 3);
        }
    #endif  
    
    if(((receivedFlags >> 4) & 1u) != 0u){
        receiveHormoneFull(CAN_RX_MAILBOX_hormoneData00);
        if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_5_SHIFT) != 0u){
            receiveHormoneFull(CAN_RX_MAILBOX_hormoneData01);
            //flag |= (1u << 0);
            CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData01);
        }
        if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_6_SHIFT) != 0u){
            receiveHormoneFull(CAN_RX_MAILBOX_hormoneData02);
            //flag |= (1u << 1);
            CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData02);
        }
        receivedFlags &= ~(1u << 4);
    }
    
    if(((receivedFlags >> 5) & 1u) != 0u){
        receiveHormoneFull(CAN_RX_MAILBOX_hormoneData10);
        if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_8_SHIFT) != 0u){
            receiveHormoneFull(CAN_RX_MAILBOX_hormoneData11);
            //flag |= (1u << 0);
            CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData11);
        }
        if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_9_SHIFT) != 0u){
            receiveHormoneFull(CAN_RX_MAILBOX_hormoneData12);
            //flag |= (1u << 1);
            CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData12);
        }
        receivedFlags &= ~(1u << 5);
    }
    
    if(((receivedFlags >> 6) & 1u) != 0u){
        receiveHormoneFull(CAN_RX_MAILBOX_hormoneData20);
        if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_11_SHIFT) != 0u){
            receiveHormoneFull(CAN_RX_MAILBOX_hormoneData21);
            //flag |= (1u << 0);
            CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData21);
        }
        if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_12_SHIFT) != 0u){
            receiveHormoneFull(CAN_RX_MAILBOX_hormoneData22);
            //flag |= (1u << 1);
            CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData22);
        }
        receivedFlags &= ~(1u << 6);
    }
    
    if(((receivedFlags >> 7) & 1u) != 0u){
        receiveHormoneFull(CAN_RX_MAILBOX_hormoneData30);
        if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_14_SHIFT) != 0u){
            receiveHormoneFull(CAN_RX_MAILBOX_hormoneData31);
            //flag |= (1u << 0);
            CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData31);
        }
        if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_15_SHIFT) != 0u){
            receiveHormoneFull(CAN_RX_MAILBOX_hormoneData32);
            //flag |= (1u << 1);
            CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_hormoneData32);
        }
        receivedFlags &= ~(1u << 7);
    }
    
    
}