#include <project.h>

#define HORM_BUFFER_SIZE  (4)

uint8 receivedFlags;//Flags: bit0(0x01):phaseBuffer1 bit1(0x02):phaseBuffer2 bit2(0x04):phaseBuffer3 bit3(0x08):phaseBuffer4
                    //Flags: bit4(0x10):hormoneBuffer1 bit5(0x20):hormoneBuffer2 bit6(0x40):hormoneBuffer3 bit7(0x80):hormoneBuffer4

float phaseBuffer[4];
uint8 hormBuffer0[HORM_BUFFER_SIZE][6];
int8 buffercount[4];


void sendPhase(float phase);
void sendHormone(uint8 horm[]);
void receivePhase(uint8 sender);
void readPhaseBuffers(float phase[]);
void receiveHormone(uint8 sender);
void readHormoneBuffers(void);
void float_encode(float p_value, uint8 * p_encoded_data);
float float_decode(uint8 * p_encoded_data);