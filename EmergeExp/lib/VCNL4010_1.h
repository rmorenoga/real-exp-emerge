#include <project.h>
#include <..\lib\VCNL4010.h>

//Send Data
void writeVCNL_1(uint8 address, uint8 data);

//Read Data
uint8 readVCNL_1(uint8 address);

//Init Sensor
void initVCNL_1(void);

//Read Distance Signal
uint16 readProximity_1(void);

//Read Ambient Signal
uint16 readAmbient_1();
