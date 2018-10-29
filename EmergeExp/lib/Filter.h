#include <project.h>
#include <..\lib\CANProtocol.h>

#define HORM_SUM_WINDOW  (7)
#define ORI_WINDOW  (12)
float hormSumArrived[HORM_SUM_WINDOW][HORM_SIZE];
int8 hormArrivedCount;
int8 oriCount[6];
int8 filteredOri;
unsigned int timeStep;

void filterHormones(float horm[],unsigned int timestep,float hormFiltered[]);
void normalizedHormoneSum(uint8 horm[] ,float hormNorm[]);
void integrate(int8 count[], uint8 horm[]);

void filterOri(int8 ori,unsigned int timestep);
int8 findMaxCount();

void advanceTimeStep();