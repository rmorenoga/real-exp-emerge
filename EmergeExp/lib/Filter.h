#include <project.h>
#include <..\lib\Hormone.h>

#define HORM_SUM_WINDOW  (7)
#define ORI_WINDOW  (12)
uint8 hormSumArrived[HORM_SUM_WINDOW][HORM_SIZE];
int8 hormArrivedCount;
int8 oriCount[6];

void filterHormones(uint8 horm[],unsigned int timestep,float hormFiltered[]);
void normalizedHormoneSum(uint8 horm[] ,float hormNorm[]);
void integrate(int8 count[], uint8 horm[]);
void sumHormones(uint8 hormTotal[], uint8 horm1[], uint8 horm2[]);

int8 filterOri(int8 ori,unsigned int timestep);
int8 findMaxCount();