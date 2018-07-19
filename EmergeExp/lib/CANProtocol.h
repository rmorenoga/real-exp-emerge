#include <project.h>

int sendPhase(float phase);
float receivePhase(int face); 
int float_encode(float p_value, uint8 * p_encoded_data);
float float_decode(uint8 * p_encoded_data);