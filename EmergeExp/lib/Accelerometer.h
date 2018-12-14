#include <project.h>
#include <math.h>
#include <stdlib.h>

#define ORIENTATION_ADDRESS (0x80)

int16 xAxis;
int16 yAxis;
int16 zAxis;

int8 readSensor(void);
void sendOrientation(int8 orientation);

int8 getOriNumber(int16 xAxis,int16 yAxis,int16 zAxis);
void int16_encode(int16 p_value, uint8 * p_encoded_data);

