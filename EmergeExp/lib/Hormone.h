#include <..\lib\Filter.h>
#include <..\lib\CPG.h>
#include <math.h>
#include <..\lib\VCNL4010_1.h>
#include <..\lib\VCNL4010_2.h>
#include <..\lib\VCNL4010_3.h>
#include <..\lib\VCNL4010_4.h>
#include <..\lib\ANNBias.h>

#define MAX_AMLPITUDE (1)
#define MIN_AMPLITUDE (-1)

#define MAX_PHASE (M_PI)
#define MIN_PHASE (-M_PI)

#define MAX_OFFSET (1)
#define MIN_OFFSET (-1)

void generateHormone(uint8 * controlFlags, uint8 horm[]);
uint8 readSensor(uint8 sensor);

void receptors(uint8 horm[]);
void convertOutputToCPGParameters(float output[]);
float convertFromUnitToRange(float value,float maxValue,float minValue);
