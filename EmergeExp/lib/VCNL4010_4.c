#include <..\lib\VCNL4010_4.h>

void writeVCNL_4(uint8 address, uint8 data){
    uint8 Write_buf[2]={0};
    Write_buf[0]=address;
    Write_buf[1]=data;
    
    SENSOR_4_I2CMasterWriteBuf(VCNL4010_ADDRESS,Write_buf,2,SENSOR_4_I2C_MODE_COMPLETE_XFER);
    while((SENSOR_4_I2CMasterStatus()&SENSOR_4_I2C_MSTAT_WR_CMPLT)==0){}
}

uint8 readVCNL_4(uint8 address){
    uint8 Write_buf = 0;
    uint8 read_Buf = 0;
    Write_buf = address;
    
    SENSOR_4_I2CMasterWriteBuf(VCNL4010_ADDRESS,&Write_buf,1,SENSOR_4_I2C_MODE_NO_STOP);
    while((SENSOR_4_I2CMasterStatus()&SENSOR_4_I2C_MSTAT_WR_CMPLT)==0){}
    SENSOR_4_I2CMasterReadBuf(VCNL4010_ADDRESS,&read_Buf,1,SENSOR_4_I2C_MODE_REPEAT_START);
    while((SENSOR_4_I2CMasterStatus()&SENSOR_4_I2C_MSTAT_RD_CMPLT)==0){}
    return read_Buf;
}

void initVCNL_4(){
  int i;
  int sensorID = readVCNL_4(VCNL4010_ID_REG);
  if (sensorID != VCNL4010_ID){  
    //Led Sequence Fail
    LED_4_Write(1);
    CyDelay(500);
    LED_4_Write(0);
    CyDelay(500);    
  }
   else{
    //Led Sequence Sucess
    LED_4_Write(0);
    for(i=1;i<5;i++){
        LED_4_Write(1);
        CyDelay(200);
        LED_4_Write(0);
        CyDelay(200); 
        }
    LED_4_Write(0);
  } 
  //VCNL Init Params
  writeVCNL_4(VCNL4010_AMBIENT_LIGHT_REG, 0x0F); // Configures ambient light measures - Single conversion mode, 128 averages
  writeVCNL_4(VCNL4010_LED_CURRENT_REG, 0x64);   // sets IR current in steps of 10mA 0-200mA --> 200mA
  writeVCNL_4(VCNL4010_ICR, 0);    // Proximity IR test signal freq, 0-3 - 781.25 kHz
  writeVCNL_4(VCNL4010_LOW_THRESHOLD, 0x81); // proximity modulator timing - 129, recommended by Vishay 
}

uint16 readProximity_4(){
  uint8 commandReg = readVCNL_4(VCNL4010_COMMAND_REG);

  writeVCNL_4(VCNL4010_COMMAND_REG, commandReg | 0x08);            // command the sensor to perform a proximity measure
  while(!(readVCNL_4(VCNL4010_COMMAND_REG) & 0x20));            // wait for the proximity data ready bit to be set

  uint16 data = readVCNL_4(VCNL4010_PROXIMITY_HIGH) << 8;
  data |= readVCNL_4(VCNL4010_PROXIMITY_LOW);

  return data;
}

uint16 readAmbient_4(){
  uint8 commandReg = readVCNL_4(VCNL4010_COMMAND_REG);

  writeVCNL_4(VCNL4010_COMMAND_REG, commandReg | 0x10);             // command the sensor to perform ambient measure
  while(!(readVCNL_4(VCNL4010_COMMAND_REG) & 0x40));            // wait for the proximity data ready bit to be set

  uint16 data = readVCNL_4(VCNL4010_AMBIENT_HIGH) << 8;  
  data |= readVCNL_4(VCNL4010_AMBIENT_LOW);

  return data;
}

