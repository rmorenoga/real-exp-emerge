#include <..\lib\Hormone.h>


void generateHormone(uint8 * controlFlags, uint8 horm[]){
    
    uint8 SensorValues[4]={0u};
    uint8 i;
    
    SensorValues[0] = readSensor(1u);
    SensorValues[1] = 0u;//readSensor(2u);
    SensorValues[2] = readSensor(3u);
    SensorValues[3] = 0u;//readSensor(4u);
    
    for (i=0;i < 4;i++){
        if(SensorValues[i] != 0u){
            (*controlFlags) |= 0x01u;
        }
    }
    
    horm[0] = SensorValues[0];
    horm[1] = SensorValues[1];
    horm[2] = SensorValues[2];
    horm[3] = SensorValues[3];
    horm[4] = 0;
    horm[5] = 0;    
}

/*void sendHormone(uint16 horm[6]){
    
    sendHormoneMessageHigh(horm);
    sendHormoneMessageLow(horm);
        
}*/

uint8 readSensor(uint8 sensor){
    uint16 reading = 0u;
    switch (sensor){
        case 1u :
            reading = readProximity_1();
            break;
        case 2u :
            reading = readProximity_2();
            break;
        case 3u :
            reading = readProximity_3();
            break;
        case 4u :
            reading = readProximity_4();
            break;
    }
    
    if(reading < 2883u){
        return 0u;
    }else{
        return reading >> 8;
    }
}

