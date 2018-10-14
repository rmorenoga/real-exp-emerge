#include <..\lib\SpTransform.h>

int8 f11[ORIENTATIONS][HORM_SIZE] = {{1,2,3,4,5,6},{1,2,5,6,4,3},{1,2,4,3,6,5},{1,2,6,5,3,4}};
int8 f12[ORIENTATIONS][HORM_SIZE] = {{4,3,1,2,5,6},{4,3,5,6,2,1},{4,3,2,1,6,5},{4,3,6,5,1,2}};
int8 f13[ORIENTATIONS][HORM_SIZE] = {{3,4,2,1,5,6},{3,4,5,6,1,2},{3,4,1,2,6,5},{3,4,6,5,2,1}};

int8 f2[ORIENTATIONS][HORM_SIZE] = {{1,2,3,4,5,6},{1,2,6,5,3,4},{1,2,4,3,6,5},{1,2,5,6,4,3}};
int8 f3[ORIENTATIONS][HORM_SIZE] = {{3,4,2,1,5,6},{6,5,2,1,3,4},{4,3,2,1,6,5},{5,6,2,1,4,3}};
int8 f4[ORIENTATIONS][HORM_SIZE] = {{4,3,1,2,5,6},{5,6,1,2,3,4},{3,4,1,2,6,5},{6,5,1,2,4,3}};


void spHormoneTransform(uint8 horm[],int8 face,int8 connori,float hormTransformed[]){
        
    int8 entry[HORM_SIZE];
    int8 i;
    if (face == 1){
        int8 dadFace = floor(connori/10);
        int8 myOri = connori - (dadFace*10);
        switch (dadFace){
         case 1: 
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f11[myOri][i];
            }
            break;
         case 2:
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f12[myOri][i];
            }
            break;
         case 3:
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f13[myOri][i];
            }
            break;
        }
        
        for (i=0;i<HORM_SIZE;i++){
            hormTransformed[i] = horm[entry[i]];
        }
    }else{    
        switch (face){
         case 2: 
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f2[connori][i];
            }
            break;
         case 3:
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f3[connori][i];
            }
            break;
         case 4:
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f4[connori][i];
            }
            break;
        }
        
        for (i=0;i<HORM_SIZE;i++){
            hormTransformed[i] = horm[entry[i]];
        }
        
    }
    
    
   
    
}

