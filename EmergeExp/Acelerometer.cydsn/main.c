//Import Libraries
#include <project.h>
#include <..\lib\Accelerometer.h>


int8 orientation = 0;

int main()
{
    LED_1_Write(0);
    ADC_Start();
    ADC_StartConvert();
    //Multiplexor_Start();
    CAN_Start();  //Start CAN
    CAN_SET_TX_ID_STANDARD_MSG(0,ORIENTATION_ADDRESS);
    CyGlobalIntEnable;
    for(;;){
        LED_1_Write(0);
        CyDelay(400);
        orientation = readSensor();
        sendOrientation(orientation);
        LED_1_Write(1);
        CyDelay(400);
    }
    
    
    
}

