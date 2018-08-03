#include <project.h>
#include <..\lib\VCNL4010.h>

//Send Data
void writeVCNL_3(uint8 address, uint8 data);

//Read Data
uint8 readVCNL_3(uint8 address);

//Init Sensor
void initVCNL_3(void);

//Read Distance Signal
uint16 readProximity_3(void);

//Read Ambient Signal
uint16 readAmbient_3();