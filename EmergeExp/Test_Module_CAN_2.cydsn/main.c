#include <project.h>
//Import Libraries
#include <AX12.h>
#include <VCNL4010_1.h>
#include <VCNL4010_2.h>
#include <VCNL4010_3.h>
#include <VCNL4010_4.h>
// If any sensor does not work the program will not start
//Global Variables
int16 S1=0,S2=0,S3=0,S4=0;
uint8 dato_enviado;
uint8 dato_recibido;


int main()
{
	CyGlobalIntEnable; 
	//Init LED's
	LED_1_Write(0);
	LED_2_Write(0);
	LED_3_Write(0);
	//LED_4_Write(0);
	//Init CAN
	CAN_Start();
	//Init Serial
	MOTOR_Start();
	//Init Sensor's
	SENSOR_1_Start();
	SENSOR_1_Enable();
	//SENSOR_2_Start();
	//SENSOR_2_Enable();
	SENSOR_3_Start();
	SENSOR_3_Enable();
	//SENSOR_4_Start();
	//SENSOR_4_Enable();    
	CyDelay(100);
	initVCNL_1();
	//initVCNL_2();
	initVCNL_3();
	//initVCNL_4();
	for(;;)
	{
		
    //Send and read data over CAN 
		//CAN_SendMsg0();
		//CyDelay(500);
		//dato_enviado++;
		CAN_ReceiveMsg0();
		if(dato_recibido==30){
            LED_1_Write(0);
            LED_2_Write(1);
            LED_3_Write(0);
        }
		else if(dato_recibido==10){
            LED_1_Write(0);
            LED_2_Write(0);
            LED_3_Write(1);
        }
        else if(dato_recibido==20){
            LED_1_Write(1);
            LED_2_Write(0);
            LED_3_Write(0);
        }
	}
}

