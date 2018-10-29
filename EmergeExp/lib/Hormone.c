#include <..\lib\Hormone.h>


void generateHormone(uint8 * controlFlags, uint8 horm[]){
    
    uint8 SensorValues[4]={0u};
    uint8 i;
    
    SensorValues[0] = readSensor(1u);
    SensorValues[1] = readSensor(2u);
    SensorValues[2] = readSensor(3u);
    SensorValues[3] = readSensor(4u);
    
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

void receptors(uint8 horm[]){
    float hormSummed[HORM_SIZE];
    float hormFiltered[HORM_SIZE];
    float output[ANN_OUTPUT_SIZE];
    
    normalizedHormoneSum(horm,hormSummed);
    filterHormones(hormSummed,timeStep,hormFiltered);
    propagateANN(hormFiltered,output);
    convertOutputToCPGParameters(output);
    
    advanceTimeStep();
}

void convertOutputToCPGParameters(float output[]){
    ampliSet = convertFromUnitToRange(output[0],MAX_AMLPITUDE,MIN_AMPLITUDE);
    offsetSet = convertFromUnitToRange(output[1],MAX_OFFSET,MIN_OFFSET);
    phaseDiffSet[0] =  convertFromUnitToRange(output[2],MAX_PHASE,MIN_PHASE);
    phaseDiffSet[1] =  convertFromUnitToRange(output[3],MAX_PHASE,MIN_PHASE);
}

float convertFromUnitToRange(float value,float maxValue,float minValue){
    return (((value)*(maxValue-minValue))) + minValue;
}
