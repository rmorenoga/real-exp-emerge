#include <project.h>


#define MODULE_0
//#define MODULE_1
//#define MODULE_2
//#define MODULE_3
//#define MODULE_4
//#define MODULE_5
//#define MODULE_6
//#define MODULE_7
#define AMR (0x001FFFF9) /* AMR (Bit[31;21]is Mask set to 0 for ID, Bit[20:3]=1, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
#define ACR_ORIENTATION (0x10000000)
int8 connh[4] = {-1,-1,-1,-1}; 


#ifdef MODULE_0
    #define MODULE_NUMBER (0)
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x007)
    #define ACR_PHASE0 (0x00400000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01000000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000) 
#endif

#ifdef MODULE_1
    #define MODULE_NUMBER (1)
    #define PHASE_ID (0x002)
    #define HORMONE_ID (0x008)
    #define ACR_PHASE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x00200000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01200000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x00e00000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif

#ifdef MODULE_2
    #define MODULE_NUMBER (2)
    #define PHASE_ID (0x003)
    #define HORMONE_ID (0x009)
    #define ACR_PHASE0 (0x00800000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x00400000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01400000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x01000000)
    #define ACR_HORMONE3 (0x0fe00000)    
#endif
#ifdef MODULE_3
    #define MODULE_NUMBER (3)
    #define PHASE_ID (0x004)
    #define HORMONE_ID (0x00a)
    #define ACR_PHASE0 (0x00a00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x00600000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x01200000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif
#ifdef MODULE_4
    #define MODULE_NUMBER (4)
    #define PHASE_ID (0x005)
    #define HORMONE_ID (0x00b)
    #define ACR_PHASE0 (0x00c00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x00800000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01800000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x01400000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif
#ifdef MODULE_5
    #define MODULE_NUMBER (5)
    #define PHASE_ID (0x006)
    #define HORMONE_ID (0x00c)
    #define ACR_PHASE0 (0x01a00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x00a00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01e00000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x01600000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif
#ifdef MODULE_6
    #define MODULE_NUMBER (6)
    #define PHASE_ID (0x00d)
    #define HORMONE_ID (0x00f)
    #define ACR_PHASE0 (0x01c00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x00c00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x02000000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x01800000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif

#ifdef MODULE_7
    #define MODULE_NUMBER (7)
    #define PHASE_ID (0x00e)
    #define HORMONE_ID (0x010)
    #define ACR_PHASE0 (0x0fe00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x01a00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x0fe00000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x01e00000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif

    
    
void configureCANID(void){
    
    CY_SET_REG32((reg32 *)(&CAN_RX[0].rxamr),AMR); // Set receiving mask for rx 0
    CY_SET_REG32((reg32 *)(&CAN_RX[0].rxacr),ACR_PHASE0); // Set receiving id for rx 0, id can be set with three hexadecimal numbers (0x001 for example) 
    CY_SET_REG32((reg32 *)(&CAN_RX[1].rxamr),AMR); // Set receiving mask for rx 1
    CY_SET_REG32((reg32 *)(&CAN_RX[1].rxacr),ACR_PHASE1); // Set receiving id for rx 1, id can be set with three hexadecimal numbers (0x001 for example) 
    CY_SET_REG32((reg32 *)(&CAN_RX[2].rxamr),AMR); // Set receiving mask for rx 2
    CY_SET_REG32((reg32 *)(&CAN_RX[2].rxacr),ACR_PHASE2); // Set receiving id for rx 2, id can be set with three hexadecimal numbers (0x001 for example) 
    CY_SET_REG32((reg32 *)(&CAN_RX[3].rxamr),AMR); // Set receiving mask for rx 3
    CY_SET_REG32((reg32 *)(&CAN_RX[3].rxacr),ACR_PHASE3); // Set receiving id for rx 3, id can be set with three hexadecimal numbers (0x001 for example) 
    
    CY_SET_REG32((reg32 *)(&CAN_RX[4].rxamr),AMR); // Set receiving mask for rx 4
    CY_SET_REG32((reg32 *)(&CAN_RX[4].rxacr),ACR_HORMONE0);
    CY_SET_REG32((reg32 *)(&CAN_RX[5].rxamr),AMR); // Set receiving mask for rx 5
    CY_SET_REG32((reg32 *)(&CAN_RX[5].rxacr),ACR_HORMONE0);
    CY_SET_REG32((reg32 *)(&CAN_RX[6].rxamr),AMR); // Set receiving mask for rx 6
    CY_SET_REG32((reg32 *)(&CAN_RX[6].rxacr),ACR_HORMONE0);
    CY_SET_REG32((reg32 *)(&CAN_RX[7].rxamr),AMR); // Set receiving mask for rx 7
    CY_SET_REG32((reg32 *)(&CAN_RX[7].rxacr),ACR_HORMONE1);
    CY_SET_REG32((reg32 *)(&CAN_RX[8].rxamr),AMR); // Set receiving mask for rx 8
    CY_SET_REG32((reg32 *)(&CAN_RX[8].rxacr),ACR_HORMONE1);
    CY_SET_REG32((reg32 *)(&CAN_RX[9].rxamr),AMR); // Set receiving mask for rx 9
    CY_SET_REG32((reg32 *)(&CAN_RX[9].rxacr),ACR_HORMONE1);
    CY_SET_REG32((reg32 *)(&CAN_RX[10].rxamr),AMR); // Set receiving mask for rx 10
    CY_SET_REG32((reg32 *)(&CAN_RX[10].rxacr),ACR_HORMONE2);
    CY_SET_REG32((reg32 *)(&CAN_RX[11].rxamr),AMR); // Set receiving mask for rx 11
    CY_SET_REG32((reg32 *)(&CAN_RX[11].rxacr),ACR_HORMONE2);
    CY_SET_REG32((reg32 *)(&CAN_RX[12].rxamr),AMR); // Set receiving mask for rx 12
    CY_SET_REG32((reg32 *)(&CAN_RX[12].rxacr),ACR_HORMONE2);
    CY_SET_REG32((reg32 *)(&CAN_RX[13].rxamr),AMR); // Set receiving mask for rx 13
    CY_SET_REG32((reg32 *)(&CAN_RX[13].rxacr),ACR_HORMONE3);
    CY_SET_REG32((reg32 *)(&CAN_RX[14].rxamr),AMR); // Set receiving mask for rx 14
    CY_SET_REG32((reg32 *)(&CAN_RX[14].rxacr),ACR_HORMONE3);
    CY_SET_REG32((reg32 *)(&CAN_RX[15].rxamr),AMR); // Set receiving mask for rx 15
    CY_SET_REG32((reg32 *)(&CAN_RX[15].rxacr),ACR_HORMONE3);
    
    CAN_SET_TX_ID_STANDARD_MSG(0, PHASE_ID);  // Set transmit id for tx 0
    CAN_SET_TX_ID_STANDARD_MSG(1, HORMONE_ID);  // Set transmit id for tx 1
    
    #ifdef MODULE_0
        connh[0] = 1;
        connh[1] = -1;
        connh[2] = -1;
        connh[3] = -1;
    #endif
    
    #ifdef MODULE_1
        connh[0] = 2;
        connh[1] = -1;
        connh[2] = 0;
        connh[3] = -1;
    #endif
    
    #ifdef MODULE_2
        connh[0] = 3;
        connh[1] = -1;
        connh[2] = 1;
        connh[3] = -1;
    #endif
    
    #ifdef MODULE_3
        connh[0] = 4;
        connh[1] = -1;
        connh[2] = 2;
        connh[3] = -1;
    #endif
    
    #ifdef MODULE_4
        connh[0] = 5;
        connh[1] = -1;
        connh[2] = 3;
        connh[3] = -1;
    #endif
    
    #ifdef MODULE_5
        connh[0] = 6;
        connh[1] = -1;
        connh[2] = 4;
        connh[3] = -1;
    #endif
    
     #ifdef MODULE_6
        connh[0] = 7;
        connh[1] = -1;
        connh[2] = 5;
        connh[3] = -1;
    #endif
    
     #ifdef MODULE_7
        connh[0] = -1;
        connh[1] = -1;
        connh[2] = 6;
        connh[3] = -1;
    #endif
}