#include <..\lib\Accelerometer.h>

int16 xAxis = 0;
int16 yAxis = 0;
int16 zAxis = 0;

int8 readSensor(void){
    
   // int16 xAxis = 0;
   // int16 yAxis = 0;
    
   // int16 zAxis = 0;
    int8 ori = 0;
    
   // Multiplexor_Select(0);
    xAxis = ADC_GetResult16(0);
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
   // Multiplexor_Select(1);
    yAxis = ADC_GetResult16(1);
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
   // Multiplexor_Select(2);
    zAxis = ADC_GetResult16(2);
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    ori = getOriNumber(xAxis,yAxis,zAxis);
    
    return ori;
}


void sendOrientation(int8 orientation){
    
    uint8 byteReadingX[2];
    uint8 byteReadingY[2];
    uint8 byteReadingZ[2];
    
   /*     
    CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_orientation,orientation);
    CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_orientation,0u);
    */
    
    int16_encode(xAxis,byteReadingX);
    int16_encode(yAxis,byteReadingY);
    int16_encode(zAxis,byteReadingZ);
    
    CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_orientation,byteReadingX[0]);
    CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_orientation,byteReadingX[1]);
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_orientation,byteReadingY[0]);
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_orientation,byteReadingY[1]);
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_orientation,byteReadingZ[0]);
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_orientation,byteReadingZ[1]);
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_orientation,0u);
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_orientation,0u);
    
    CAN_SendMsgorientation();
}

int8 getOriNumber(int16 xAxis,int16 yAxis,int16 zAxis){
    
    int8 resultOri = 0;
    int threshold = 80;
    
    const int xHigh = 840;
    const int xLow = 565;
    const int yHigh = 840;
    const int yLow = 567;
    const int zHigh = 855;
    const int zLow = 585;
    
    if (yAxis >= yHigh - threshold) {
        resultOri = 5;
    } else if(yAxis <= yLow + threshold){
        resultOri = 4;
    }
    
    if (zAxis >= zHigh - threshold) {
        resultOri = 3;
    } else if(zAxis <= zLow + threshold){
        resultOri = 1;
    }
    
    if (xAxis >= xHigh - threshold) {
        resultOri = 2;
    } else if(xAxis <= xLow + threshold){
        resultOri = 0;
    }
    
    return resultOri;
    
}

void int16_encode(int16 p_value, uint8 * p_encoded_data){
    
    union { 
        int16 int16_val;
        uint8 char_val[2];
    }encoder;

    encoder.int16_val = p_value;
    p_encoded_data[0] = encoder.char_val[0];
    p_encoded_data[1] = encoder.char_val[1];
}


