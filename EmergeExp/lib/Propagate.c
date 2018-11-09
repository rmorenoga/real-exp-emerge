#include <..\lib\Propagate.h>


void propagate(void){ //How to propagate forwards
    int8 i;
    uint8 mask;
    if (connh[0] != -1){
        for(i=0;i<buffercount[0];i++){
            mask = createMaskForward(0);
            sendHormone(hormBuffer0[i],mask);
        }
    }
    if (connh[1] != -1){
        for(i=0;i<buffercount[1];i++){
            mask = createMaskForward(1);
            sendHormone(hormBuffer1[i],mask);
        }
    }
    if (connh[2] != -1){
        for(i=0;i<buffercount[2];i++){
            mask = createMaskForward(2);
            sendHormone(hormBuffer2[i],mask);
        }
    }
    if (connh[3] != -1){
        for(i=0;i<buffercount[3];i++){
            mask = createMaskForward(3);
            sendHormone(hormBuffer3[i],mask);
        }
    }
}