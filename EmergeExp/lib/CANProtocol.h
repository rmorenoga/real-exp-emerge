#include <project.h>

#define HORM_SIZE  (6)
#define HORM_BUFFER_SIZE  (3)

uint8 receivedFlags;//Flags: bit0(0x01):phase1 bit1(0x02):phase2 bit2(0x04):phase3 bit3(0x08):phase4
                    //Flags: bit4(0x10):hormone1 bit5(0x20):hormone2 bit6(0x40):hormone3 bit7(0x80):hormone4

//float phaseBuffer[4];
uint8 hormBuffer0[HORM_BUFFER_SIZE][HORM_SIZE];
uint8 hormBuffer1[HORM_BUFFER_SIZE][HORM_SIZE];
uint8 hormBuffer2[HORM_BUFFER_SIZE][HORM_SIZE];
uint8 hormBuffer3[HORM_BUFFER_SIZE][HORM_SIZE];
int8 buffercount[4];


void sendPhase(float phase);
void sendHormone(uint8 horm[]);
//void sendHormone(void);
void receivePhase(uint8 sender, float phase[]);
//void readPhaseBuffers(float phase[]); //Deprecated
//void receiveHormone(uint8 sender);
void receiveHormoneFull(uint8 sender);
void readHormoneBuffers(void);
void float_encode(float p_value, uint8 * p_encoded_data);
float float_decode(uint8 * p_encoded_data);