#include <..\lib\Hormone.h>


void generateHormone(uint8 * controlFlags, uint8 horm[]){
    
    uint8 SensorValues[4]={0u,0u,0u,0u};
    uint8 i;
    
    if(connh[0] == -1){
        SensorValues[0] = readSensor(4u);
    }
    if(connh[1] == -1){
        SensorValues[1] = readSensor(2u);
    }
    if(connh[2] == -1){
        SensorValues[2] = readSensor(1u);
    }
    if(connh[3] == -1){
        SensorValues[3] = readSensor(3u);
    }
    
    for (i=0;i < 4;i++){
        if(SensorValues[i] != 0u){
            (*controlFlags) |= 0x01u;
        }
    }
    
    horm[0] = SensorValues[0];
    horm[1] = SensorValues[1];
    horm[2] = SensorValues[2];
    horm[3] = SensorValues[3];
    horm[4] = 0u;
    horm[5] = 0u;    
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

void receptors(uint8 horm[],int8 ori){
    float hormSummed[HORM_SIZE];
    float output[ANN_OUTPUT_SIZE];
    float input[ANN_INPUT_SIZE];
    float oriInputs[ANN_ORI_INPUT_SIZE];
    int i;
       
    normalizedHormoneSum(horm,hormSummed);
    filterHormones(hormSummed,hormFiltered);
    filterOri(ori);
    getANNInputsFromOri(oriInputs,filteredOri);
    
    for(i=0;i<HORM_SIZE;i++){
        //input[i] = convertFromRangetoUnit(hormFiltered[i], 255.0,10.0);
        input[i] = hormFiltered[i]/255.0;       
    }
    /*
    input[0] = 0.0;
    input[1] = 0.0;
    input[2] = 0.0;
    input[3] = 0.0;
    input[4] = 0.0;
    input[5] = 0.0;
    
    input[6] = 0.9;
    input[7] = 0.1;
    input[8] = 0.1;
    input[9] = 0.0;
    input[10] = 0.1;
    input[11] = 0.1;*/
    
    for (i=0;i<ANN_ORI_INPUT_SIZE;i++){
        input[i+ANN_ORI_INPUT_SIZE] = oriInputs[i];   
    }
    
    propagateANN(input,output);
    convertOutputToCPGParameters(output);
    
}

void getANNInputsFromOri(float oriInputs[],int8 orientation){
    int8 i;
    for (i = 0; i < ANN_ORI_INPUT_SIZE; i++){
        oriInputs[i] = 0.1;    
    }   
    oriInputs[orientation] = 0.9;
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

//float convertFromRangetoUnit(float value, float maxvalue,float minvalue){
	//return (value-minvalue)/(maxvalue-minvalue);
//}