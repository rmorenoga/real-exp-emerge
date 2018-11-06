#include <project.h>


#define MODULE_1
//#define MODULE_2
//#define MODULE_3
//#define MODULE_4
//#define MODULE_5
//#define MODULE_6
//#define MODULE_7
//#define MODULE_8
#define AMR (0x001FFFF9) /* AMR (Bit[31;21]is Mask set to 0 for ID, Bit[20:3]=1, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
#define ACR_ORIENTATION (0x00600000) 


#ifdef MODULE_1
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x002)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00200000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x00200000)
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x00600000)
    #define ACR_HORMONE2 (0x00600000)
    #define ACR_HORMONE3 (0x00600000) 
#endif

#ifdef MODULE_2
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x002)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00200000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x00200000)
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x00600000)
    #define ACR_HORMONE2 (0x00600000)
    #define ACR_HORMONE3 (0x00600000)  
#endif

#ifdef MODULE_3
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x002)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00200000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x00200000)
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x00600000)
    #define ACR_HORMONE2 (0x00600000)
    #define ACR_HORMONE3 (0x00600000)  
#endif
#ifdef MODULE_4
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x002)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00200000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x00200000)
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x00600000)
    #define ACR_HORMONE2 (0x00600000)
    #define ACR_HORMONE3 (0x00600000)  
#endif
#ifdef MODULE_5
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x002)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00200000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x00200000)
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x00600000)
    #define ACR_HORMONE2 (0x00600000)
    #define ACR_HORMONE3 (0x00600000)  
#endif
#ifdef MODULE_6
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x002)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00200000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x00200000)
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x00600000)
    #define ACR_HORMONE2 (0x00600000)
    #define ACR_HORMONE3 (0x00600000)  
#endif
#ifdef MODULE_7
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x002)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00200000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x00200000)
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x00600000)
    #define ACR_HORMONE2 (0x00600000)
    #define ACR_HORMONE3 (0x00600000)  
#endif

#ifdef MODULE_8
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x002)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00200000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x00200000)
    #define ACR_HORMONE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x00600000)
    #define ACR_HORMONE2 (0x00600000)
    #define ACR_HORMONE3 (0x00600000)  
#endif

    
    
void configureCANID(void){
    
    CY_SET_REG32((reg32 *)(&CAN_RX[0].rxamr),AMR); // Set receiving mask for rx 0
    CY_SET_REG32((reg32 *)(&CAN_RX[0].rxacr),ACR_PHASE0); // Set receiving id for rx 0, id can be set with three hexadecimal numbers (0x001 for example) 
    CY_SET_REG32((reg32 *)(&CAN_RX[1].rxamr),AMR); // Set receiving mask for rx 0
    CY_SET_REG32((reg32 *)(&CAN_RX[1].rxacr),ACR_PHASE1); // Set receiving id for rx 0, id can be set with three hexadecimal numbers (0x001 for example) 
    CY_SET_REG32((reg32 *)(&CAN_RX[2].rxamr),AMR); // Set receiving mask for rx 0
    CY_SET_REG32((reg32 *)(&CAN_RX[2].rxacr),ACR_PHASE2); // Set receiving id for rx 0, id can be set with three hexadecimal numbers (0x001 for example) 
    CY_SET_REG32((reg32 *)(&CAN_RX[3].rxamr),AMR); // Set receiving mask for rx 0
    CY_SET_REG32((reg32 *)(&CAN_RX[3].rxacr),ACR_PHASE3); // Set receiving id for rx 0, id can be set with three hexadecimal numbers (0x001 for example) 
    
    CY_SET_REG32((reg32 *)(&CAN_RX[4].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[4].rxacr),ACR_HORMONE0);
    CY_SET_REG32((reg32 *)(&CAN_RX[5].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[5].rxacr),ACR_HORMONE0);
    CY_SET_REG32((reg32 *)(&CAN_RX[6].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[6].rxacr),ACR_HORMONE0);
    CY_SET_REG32((reg32 *)(&CAN_RX[7].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[7].rxacr),ACR_HORMONE1);
    CY_SET_REG32((reg32 *)(&CAN_RX[8].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[8].rxacr),ACR_HORMONE1);
    CY_SET_REG32((reg32 *)(&CAN_RX[9].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[9].rxacr),ACR_HORMONE1);
    CY_SET_REG32((reg32 *)(&CAN_RX[10].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[10].rxacr),ACR_HORMONE2);
    CY_SET_REG32((reg32 *)(&CAN_RX[11].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[11].rxacr),ACR_HORMONE2);
    CY_SET_REG32((reg32 *)(&CAN_RX[12].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[12].rxacr),ACR_HORMONE2);
    CY_SET_REG32((reg32 *)(&CAN_RX[13].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[13].rxacr),ACR_HORMONE3);
    CY_SET_REG32((reg32 *)(&CAN_RX[14].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[14].rxacr),ACR_HORMONE3);
    CY_SET_REG32((reg32 *)(&CAN_RX[15].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[15].rxacr),ACR_HORMONE3);
    
    CAN_SET_TX_ID_STANDARD_MSG(0, PHASE_ID);  // Set transmit id for tx 0
    CAN_SET_TX_ID_STANDARD_MSG(1, HORMONE_ID);  // Set transmit id for tx 1
}