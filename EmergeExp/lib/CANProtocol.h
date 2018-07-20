#include <project.h>

uint8 id;
int connh[4];


void sendPhase(float phase);
void receivePhase(float * phase); 
void float_encode(float p_value, uint8 * p_encoded_data);
float float_decode(uint8 * p_encoded_data);