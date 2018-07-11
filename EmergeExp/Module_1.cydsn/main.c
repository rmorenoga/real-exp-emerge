#include <project.h>
#include <..\lib\VCNL4010_1.h>
#include <..\lib\VCNL4010_2.h>
#include <..\lib\VCNL4010_3.h>
#include <..\lib\VCNL4010_4.h>
#include <..\lib\CPG.h>


int conta=0;
uint8 mailbox0[8];
uint8 mailbox1[8];

CY_ISR(interrutcan){
    LED_3_Write(1);
    CAN_MsgRXIsr();///para marcar la interrucion como leida y resive msm

    LED_3_Write(0);
}

int main()
{  
    CyGlobalIntEnable;              /* Enable global interrupts. */
    //Init LED's
//    LED_1_Write(0);
//    LED_2_Write(0);
//    LED_3_Write(0);
//    LED_4_Write(0);
//    //Init Sensor's
//    SENSOR_1_Start();
//    SENSOR_1_Enable();
//    SENSOR_2_Start();
//    SENSOR_2_Enable();
//    SENSOR_3_Start();
//    SENSOR_3_Enable();
//    //SENSOR_4_Start();
//    //SENSOR_4_Enable();    
//
//    //initVCNL_4();
//  
//    CAN_Start();                    //  start CAN
//    CAN_isr_StartEx(interrutcan);   //interrucion can
//
//    RX_Start();                     //rx motor
//    MOTOR_Start();                  //tx motor
//    TXC_Write(3);                   // rx y tx desabilitados
//    CAN_GlobalIntEnable();

    for(;;){
    //Bucle Infinito
        
        updateCPG(3.1,2.5);
        CyDelay(500);
        
        

    }
}
