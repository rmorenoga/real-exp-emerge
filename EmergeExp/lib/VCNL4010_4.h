#include <project.h>
#include <..\lib\VCNL4010.h>

//Send Data
void writeVCNL_4(uint8 address, uint8 data);

//Read Data
uint8 readVCNL_4(uint8 address);

//Init Sensor
void initVCNL_4(void);

//Read Distance Signal
uint16 readProximity_4(void);

//Read Ambient Signal
uint16 readAmbient_4();
