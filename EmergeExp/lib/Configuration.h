#include <project.h>


#define MODULE_1
#define AMR (0x001FFFF9) /* AMR (Bit[31;21]is Mask set to 0 for ID, Bit[20:3]=1, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/



#ifdef MODULE_1
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
#endif
    
    
void configureCANID(void){
    CY_SET_REG32((reg32 *)(&CAN_RX[0].rxamr),AMR); // Set receiving mask for rx 0
    CY_SET_REG32((reg32 *)(&CAN_RX[0].rxacr),ACR_PHASE0); // Set receiving id for rx 0, id can be set with three hexadecimal numbers (0x001 for example) 
    CY_SET_REG32((reg32 *)(&CAN_RX[4].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[4].rxacr),ACR_HORMONE0);
    CY_SET_REG32((reg32 *)(&CAN_RX[5].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[5].rxacr),ACR_HORMONE0);
    CY_SET_REG32((reg32 *)(&CAN_RX[6].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[6].rxacr),ACR_HORMONE0);
    CAN_SET_TX_ID_STANDARD_MSG(0, 0x002);  // Set transmit id for tx 0
}