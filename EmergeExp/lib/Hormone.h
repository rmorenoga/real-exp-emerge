#include <..\lib\CANProtocol.h>
#include <..\lib\VCNL4010_1.h>
#include <..\lib\VCNL4010_2.h>
#include <..\lib\VCNL4010_3.h>
#include <..\lib\VCNL4010_4.h>

void generateHormone(uint8 * controlFlags, uint8 horm[]);
uint8 readSensor(uint8 sensor);
