#include <project.h>
#include <..\lib\VCNL4010_1.h>
#include <..\lib\VCNL4010_2.h>
#include <..\lib\VCNL4010_3.h>
#include <..\lib\VCNL4010_4.h>
#include <..\lib\CPG.h>


/* Global variables*/


/*Function Prototypes*/
//CY_ISR_PROTO(ISR_CAN);
CY_ISR(ISR_CAN){
    
    LED_3_Write(1);
    CAN_MsgRXIsr(); ///para marcar la interrucion como leida y resive msm 
    CyDelay(500);
    LED_3_Write(0);
}


int main()
{  
    
    uint16 phaseTx;
    uint16 phaseRx;
    /* Set CAN interrupt handler to local routine */
    //CyIntSetVector(CAN_ISR_NUMBER, ISR_CAN);    
    
    CyGlobalIntEnable;              /* Enable global interrupts. */
    //Init LED's
//    LED_1_Write(0);
//    LED_2_Write(0);
    LED_3_Write(0);
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
    CAN_Start();                    //  start CAN
    CAN_isr_StartEx(ISR_CAN);   //interrucion can
//
//    RX_Start();                     //rx motor
//    MOTOR_Start();                  //tx motor
//    TXC_Write(3);                   // rx y tx desabilitados
    CAN_GlobalIntEnable();
    
    teta[2] = -1;

    for(;;){
    //Bucle Infinito
        
        phaseRx = (CAN_RX_DATA_BYTE1(CAN_TX_MAILBOX_phaseData) << 8) + CAN_RX_DATA_BYTE2(CAN_TX_MAILBOX_phaseData);
       
        teta[1] = (float) phaseRx/10000.0;        
        
        updateCPG(teta);
        
        phaseTx = (uint16) (teta[0]*10000.0); 
        
        CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_phaseData,HI8(phaseTx));
        CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_phaseData,LO8(phaseTx));
        CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_phaseData,0u);
        CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_phaseData,0u);
        CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_phaseData,0u);
        CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_phaseData,0u);
        CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_phaseData,0u);
        CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_phaseData,0u);
        CAN_SendMsgphaseData();
        
        CyDelay(2000);
        
        

    }
}
