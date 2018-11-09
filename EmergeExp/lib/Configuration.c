#include <..\lib\Configuration.h>

int8 connh[4] = {-1,-1,-1,-1};

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