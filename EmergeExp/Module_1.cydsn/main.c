#include <project.h>
#include <..\lib\VCNL4010_1.h>
#include <..\lib\VCNL4010_2.h>
#include <..\lib\VCNL4010_3.h>
#include <..\lib\VCNL4010_4.h>
#include <..\lib\CPG.h>
#include <..\lib\CANProtocol.h>


/* Global variables*/
//Declared in each library for ease of implementation
//TODO: Reorganize global variables in main
    float angle = 0.0;
    int motorGoal;

/*Function Prototypes*/
CY_ISR_PROTO(ISR_CAN); // CAN Interruption handler declaration
int convertAngleToPosition(float input, int maxPos, int minPos);


int main()
{  
    /*Morphology Configuration Parameters*/
    id = 0;
    connh[0] = -1;
    connh[1] = 1;
    connh[2] = -1;
    connh[3] = -1;
    
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

        updateCPG(teta);            // Update CPG Equations
        angle = (offset+(cos(teta[0])*ampli)); // Calculate motor position
        motorGoal = convertAngleToPosition(angle,800,200);                                    
        
        sendPhase(teta[0]);         // Send phase through CAN
        CyDelay(1000);              // Wait for 1 second and repeats
    }
}

CY_ISR(ISR_CAN){
    
    CAN_MsgRXIsr();                 // Clear Receive Message interrupt flag and calls appropriate handlers
    receivePhase(teta);                 // Receive phase information and updtates appropiate phase (teta) field

}

int convertAngleToPosition(float input, int maxPos, int minPos){
    
    int output = 0;
    float oldRange = 1-(-1);
    float newRange = maxPos - minPos;
    float convertedInput =  (((input - (-1)) * newRange) / oldRange) + minPos;
    
    output = convertedInput;
    
    return output;    
}
