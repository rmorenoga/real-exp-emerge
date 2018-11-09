#include <..\lib\Filter.h>

int8 hormArrivedCount = -1;
int8 oriArrivedCount = -1;
int8 oriCount[6] = {0,0,0,0,0,0};
int8 filteredOri = 0;
//unsigned int timeStep = 0;

void filterHormones(float horm[],float hormFiltered[]){
    
    float hormSumTotal[HORM_SIZE] = {0.0,0.0,0.0,0.0,0.0,0.0};
    int8 i;
    int8 j;
    
    if (hormArrivedCount == -1){
        for (i=0;i<HORM_SIZE;i++){
            hormFiltered[i] = horm[i];
        }
        hormArrivedCount++;
    }
    
    for(i = 0;i<HORM_SIZE;i++){
        hormSumArrived[hormArrivedCount][i] = horm[i];    
    }
    hormArrivedCount++;
    
    //if((timestep%HORM_SUM_WINDOW)==0){
    if (hormArrivedCount==HORM_SUM_WINDOW){
        for (i = 0;i<hormArrivedCount;i++){
            for (j = 0;j<HORM_SIZE;j++){
                hormSumTotal[j] = hormSumTotal[j]+hormSumArrived[i][j]; 
            }
        }
        for(i = 0;i<HORM_SIZE;i++){
            hormFiltered[i] = hormSumTotal[i]/hormArrivedCount;   
        }
        hormArrivedCount = 0;
    }
}

void normalizedHormoneSum(uint8 horm[] ,float hormNorm[]){
    
    int8 count[HORM_SIZE] = {0,0,0,0,0,0};
    int8 i;
    int8 j;
    uint8 hormSum[HORM_SIZE] = {0u,0u,0u,0u,0u,0u};
    
    for(i=0;i<HORM_SIZE;i++){
        hormSum[i] = horm[i];    
    }
    
    integrate(count,horm);
    
    for (i=0;i<buffercount[0];i++){
        integrate(count,hormBuffer0[i]);
        for(j=0;j<HORM_SIZE;j++){
            hormSum[j] = hormSum[j] + hormBuffer0[i][j];  
        }
    }
    
    for (i=0;i<buffercount[1];i++){
        integrate(count,hormBuffer1[i]);
        for(j=0;j<HORM_SIZE;j++){
            hormSum[j] = hormSum[j] + hormBuffer1[i][j];  
        }
    }
    
    for (i=0;i<buffercount[2];i++){
        integrate(count,hormBuffer2[i]);
        for(j=0;j<HORM_SIZE;j++){
            hormSum[j] = hormSum[j] + hormBuffer2[i][j];  
        }
    }
    
    for (i=0;i<buffercount[3];i++){
        integrate(count,hormBuffer3[i]);
        for(j=0;j<HORM_SIZE;j++){
            hormSum[j] = hormSum[j] + hormBuffer3[i][j];  
        }
    }
        
    for(i=0;i<HORM_SIZE;i++){
        if(count[i]==0){
            hormNorm[i] = 0;
        }else{
            hormNorm[i] = ((float)hormSum[i])/count[i];   
        }
    } 
}



void integrate(int8 count[], uint8 horm[]){
    
    int8 i;
    for (i=0;i<HORM_SIZE;i++){
        if(horm[i]!=0u){
            count[i]++;   
        }
    }
    
}

void filterOri(int8 ori){
    int8 i;
    if(oriArrivedCount == -1){
        filteredOri = ori;
        oriArrivedCount++;
    }
    
    if (ori!=-1){
        oriCount[ori]++;
    }
    oriArrivedCount++;
    //if((timestep%ORI_WINDOW)==0){
    if (oriArrivedCount==ORI_WINDOW){
        filteredOri = findMaxCount();
        for (i=0;i<6;i++){
            oriCount[i] = 0;
        }
        oriArrivedCount = 0;
    }     
}


int8 findMaxCount(){
    int8 maxCount = 0;
    int8 index = -1;
    int8 i;
    
    for (i=0;i<6;i++){
        if(oriCount[i]>maxCount){
            index = i;
            maxCount = oriCount[i];
        }
    }
    
    return index;
}
