#include <project.h>
#include <math.h>
#include <..\lib\Hormone.h>

#define ORIENTATIONS (4)
int8 f11[ORIENTATIONS][HORM_SIZE];
int8 f12[ORIENTATIONS][HORM_SIZE];
int8 f13[ORIENTATIONS][HORM_SIZE];

int8 f2[ORIENTATIONS][HORM_SIZE];
int8 f3[ORIENTATIONS][HORM_SIZE];
int8 f4[ORIENTATIONS][HORM_SIZE];

void spHormoneTransform(uint8 horm[],int8 face,int8 connori,float hormTransformed[]);