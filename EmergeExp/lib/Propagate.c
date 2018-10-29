#include <..\lib\Propagate.h>


void propagate(void){ //How to propagate forwards
    int8 i;
    for(i=0;i<buffercount[0];i++){
        sendHormone(hormBuffer0[i]);
    }
    for(i=0;i<buffercount[1];i++){
        sendHormone(hormBuffer1[i]);
    }
    for(i=0;i<buffercount[2];i++){
        sendHormone(hormBuffer2[i]);
    }
    for(i=0;i<buffercount[3];i++){
        sendHormone(hormBuffer3[i]);
    }
}