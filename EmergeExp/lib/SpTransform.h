#include <project.h>
#include <math.h>
#include <..\lib\CANProtocol.h>

#define ORIENTATIONS (4)
int8 f11[ORIENTATIONS][HORM_SIZE];
int8 f12[ORIENTATIONS][HORM_SIZE];
int8 f13[ORIENTATIONS][HORM_SIZE];

int8 f2[ORIENTATIONS][HORM_SIZE];
int8 f3[ORIENTATIONS][HORM_SIZE];
int8 f4[ORIENTATIONS][HORM_SIZE];

int8 connOri[4];

void spHormoneTransform(uint8 horm[],int8 face,int8 connori,uint8 hormTransformed[]);
void spTransformBuffer(int8 face);
void spTransformAllBuffers(void);