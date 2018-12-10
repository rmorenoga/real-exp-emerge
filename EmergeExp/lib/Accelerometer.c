#include <..\lib\Accelerometer.h>

int16 xAxis = 0;
int16 yAxis = 0;
int16 zAxis = 0;

int8 readSensor(void){
    
   // int16 xAxis = 0;
   // int16 yAxis = 0;
   // int16 zAxis = 0;
    int8 ori = 0;
    
    xAxis = ADC_GetResult16(0);
    yAxis = ADC_GetResult16(1);
    zAxis = ADC_GetResult16(2);
    
    ori = getOriNumber(xAxis,yAxis,zAxis);
    
    return ori;
}


void sendOrientation(int8 orientation){
    
    CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_orientation,orientation);
    CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_orientation,0u);
    
    
    CAN_SendMsgorientation();
}

int8 getOriNumber(int16 xAxis,int16 yAxis,int16 zAxis){
    int8 resultOri = 0;
    int threshold = 30;
    
    int xRead = 1042;
    int yRead = 1154;
    int zRead = 868;
    
    if( xAxis < xRead + threshold && xAxis > xRead - threshold){
        if (yAxis < yRead + threshold && yAxis > yRead - threshold){
            if(zAxis < zRead + threshold && zAxis > zRead - threshold){
                resultOri = 0;
            }
        }
    } 
    
    xRead = 955;
    yRead = 1087;
    zRead = 722;
    
    if( xAxis < xRead + threshold && xAxis > xRead - threshold){
        if (yAxis < yRead + threshold && yAxis > yRead - threshold){
            if(zAxis < zRead + threshold && zAxis > zRead - threshold){
                resultOri = 1;
            }
        }
    } 
    
    xRead = 956;
    yRead = 1090;
    zRead = 730;
    
    if( xAxis < xRead + threshold && xAxis > xRead - threshold){
        if (yAxis < yRead + threshold && yAxis > yRead - threshold){
            if(zAxis < zRead + threshold && zAxis > zRead - threshold){
                resultOri = 2;
            }
        }
    } 
    
    xRead = 953;
    yRead = 1087;
    zRead = 712;
    
    if( xAxis < xRead + threshold && xAxis > xRead - threshold){
        if (yAxis < yRead + threshold && yAxis > yRead - threshold){
            if(zAxis < zRead + threshold && zAxis > zRead - threshold){
                resultOri = 3;
            }
        }
    } 
    
    xRead = 960;
    yRead = 1145;
    zRead = 744;
    
    if( xAxis < xRead + threshold && xAxis > xRead - threshold){
        if (yAxis < yRead + threshold && yAxis > yRead - threshold){
            if(zAxis < zRead + threshold && zAxis > zRead - threshold){
                resultOri = 4;
            }
        }
    } 
    
    xRead = 845;
    yRead = 1040;
    zRead = 589;
    
    if( xAxis < xRead + threshold && xAxis > xRead - threshold){
        if (yAxis < yRead + threshold && yAxis > yRead - threshold){
            if(zAxis < zRead + threshold && zAxis > zRead - threshold){
                resultOri = 5;
            }
        }
    } 
    
    return resultOri;
    
}


