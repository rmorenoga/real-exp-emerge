#include <..\lib\SpTransform.h>

int8 f11[ORIENTATIONS][HORM_SIZE] = {{1,2,3,4,5,6},{1,2,5,6,4,3},{1,2,4,3,6,5},{1,2,6,5,3,4}};
int8 f12[ORIENTATIONS][HORM_SIZE] = {{4,3,1,2,5,6},{4,3,5,6,2,1},{4,3,2,1,6,5},{4,3,6,5,1,2}};
int8 f13[ORIENTATIONS][HORM_SIZE] = {{3,4,2,1,5,6},{3,4,5,6,1,2},{3,4,1,2,6,5},{3,4,6,5,2,1}};

int8 f2[ORIENTATIONS][HORM_SIZE] = {{1,2,3,4,5,6},{1,2,6,5,3,4},{1,2,4,3,6,5},{1,2,5,6,4,3}};
int8 f3[ORIENTATIONS][HORM_SIZE] = {{3,4,2,1,5,6},{6,5,2,1,3,4},{4,3,2,1,6,5},{5,6,2,1,4,3}};
int8 f4[ORIENTATIONS][HORM_SIZE] = {{4,3,1,2,5,6},{5,6,1,2,3,4},{3,4,1,2,6,5},{6,5,1,2,4,3}};

/* Face starts from 1 to maintain compatibility with simulation part */
/* connori also comes from simulation */
void spHormoneTransform(uint8 horm[],int8 face,int8 connori,uint8 hormTransformed[]){
        
    int8 entry[HORM_SIZE];
    int8 i;
    if (face == 1){
        int8 dadFace = floor(connori/10);
        int8 myOri = (connori - (dadFace*10))-1;
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
            hormTransformed[i] = horm[entry[i]-1];
        }
    }else{    
        switch (face){
         case 2: 
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f2[connori-1][i];
            }
            break;
         case 3:
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f3[connori-1][i];
            }
            break;
         case 4:
            for(i=0;i<HORM_SIZE;i++){
                entry[i] = f4[connori-1][i];
            }
            break;
        }
        
        for (i=0;i<HORM_SIZE;i++){
            hormTransformed[i] = horm[entry[i]-1];
        }       
    } 
}
/* Transforms the buffer specified by face */
void spTransformBuffer(int8 face){
    uint8 hormTransformed[HORM_SIZE];
    int8 i,j;
    switch(face){
        case 1:
            for (i=0; i<buffercount[0];i++){
                spHormoneTransform(hormBuffer0[i],face,connOri[0],hormTransformed);
                for (j = 0; j<HORM_SIZE;j++){
                    hormBuffer0[i][j] = hormTransformed[j];
                }    
            }
            break; 
        case 2:
            for (i=0; i<buffercount[1];i++){
                spHormoneTransform(hormBuffer1[i],face,connOri[1],hormTransformed);
                for (j = 0; j<HORM_SIZE;j++){
                    hormBuffer1[i][j] = hormTransformed[j];
                }    
            }
            break; 
        case 3:
            for (i=0; i<buffercount[2];i++){
                spHormoneTransform(hormBuffer2[i],face,connOri[2],hormTransformed);
                for (j = 0; j<HORM_SIZE;j++){
                    hormBuffer2[i][j] = hormTransformed[j];
                }    
            }
            break; 
        case 4:
            for (i=0; i<buffercount[3];i++){
                spHormoneTransform(hormBuffer3[i],face,connOri[3],hormTransformed);
                for (j = 0; j<HORM_SIZE;j++){
                    hormBuffer3[i][j] = hormTransformed[j];
                }    
            }
            break; 
    }
}

void spTransformAllBuffers(){
    int8 i;
    for (i = 0; i<4;i++){
        if(connOri[i] != -1){
            spTransformBuffer(i+1);
        } 
    }
}