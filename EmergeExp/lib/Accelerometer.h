#include <project.h>
#include <math.h>

#define ORIENTATION_ADDRESS (0x80)

int16 xAxis;
int16 yAxis;
int16 zAxis;

int8 readSensor(void);
void sendOrientation(int8 orientation);

int8 getOriNumber(int16 xAxis,int16 yAxis,int16 zAxis);

