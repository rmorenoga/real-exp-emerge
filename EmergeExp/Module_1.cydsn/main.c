#include <project.h>
#include <..\lib\CPG.h>
#include <..\lib\CANProtocol.h>
#include <..\lib\Hormone.h>

#define CAN_RX_MAILBOX_0_SHIFT      (1u)
#define CAN_RX_MAILBOX_1_SHIFT      (2u)

/* Reset received mailbox number define */
#define RX_MAILBOX_RESET 			(0xFFu)

/* Global variables*/
//Declared in each library for ease of implementation
//TODO: Reorganize global variables in main
    float angle = 0.0;
    int motorGoal;
    uint8 controlFlags = 0x00; //Flags: bit0(0x01):SendHormone bit1(0x02):N/A bit2(0x04):N/A bit3(0x08):N/A
                        //Flags: bit4(0x10):N/A         bit5(0x20):N/A bit6(0x40):N/A bit7(0x80):N/A
    uint8 horm[6];
    
    
//uint8 receiveMailboxNumber = RX_MAILBOX_RESET; // Global variable used to store receive message mailbox number

/*Function Prototypes*/
CY_ISR_PROTO(ISR_CAN); // CAN Interruption handler declaration
int convertAngleToPosition(float input, int maxPos, int minPos);


int main()
{  
    /*Morphology Configuration Parameters (now at the can buffer configuration)*/

    
    /*Initialization Routines*/
    //Init LED's
    LED_3_Write(0);    
    CAN_Start();                    //  Start CAN module
    
    //CyIntSetVector(CAN_ISR_NUMBER, ISR_CAN); // Set CAN interrupt handler to local routine
    CAN_isr_StartEx(ISR_CAN);       // Equivalent to last instruction 
    
    CyGlobalIntEnable;              // Enable global interrupts
    //CAN_GlobalIntEnable();        // Equivalent to last instruction

    /*Loop Forever*/
    for(;;){
        
        //Read and clear phase and hormone buffers
            //Read and clear phase buffer
            readPhaseBuffers(teta);
            readHormoneBuffers();
            
        
        //Sense environment
            //Clear SendHormone flag
            controlFlags &= ~(0x01);// clear a bit with: number &= ~(1u << n);
            //Read Sensors and create hormone
        generateHormone(&controlFlags,horm);
        
        
        
        //CPG and movement
        updateCPG(teta);            // Update CPG Equations
        angle = (offset+(cos(teta[0])*ampli)); // Calculate motor position
        motorGoal = convertAngleToPosition(angle,800,200);                                    
        //Move motor to motorGoal
        
        //Send phase message
        sendPhase(teta[0]);         // Send phase through CAN
        
        //Send Generated Hormone message
        if ((controlFlags & 0x01) != 0u){
            sendHormone(horm);
        }
        
        //Propagate received hormone message
        
        
        
        
        CyDelay(1000);              // Wait for 1 second and repeat
    }
}

CY_ISR(ISR_CAN){
    
    CAN_MsgRXIsr();                 // Clear Receive Message interrupt flag and calls appropriate handlers
    
    //Identify message header (see isr example)
    //If phase data
    if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_0_SHIFT) != 0u){
        receivePhase(CAN_RX_MAILBOX_phaseData0);         // Receive phase information and store in buffer
    }
    
    //If Hormone Data
     if((CAN_BUF_SR_REG & CAN_RX_MAILBOX_1_SHIFT) != 0u){
        receiveHormone(CAN_RX_MAILBOX_hormoneData0);     // Receive hormone information and updtates appropiate buffer
    }
        //Identify Sender
        //Transform data (rearrange)
        //Store in sender buffer
            //If sender buffer full
                //Discard message
        //Add to filtered value

}

int convertAngleToPosition(float input, int maxPos, int minPos){
    
    int output = 0;
    float oldRange = 1-(-1);
    float newRange = maxPos - minPos;
    float convertedInput =  (((input - (-1)) * newRange) / oldRange) + minPos;
    
    output = convertedInput;
    
    return output;    
}
