#include <project.h>

#define CAN_RX_MAILBOX_0_SHIFT      (1u)
#define CAN_RX_MAILBOX_1_SHIFT      (2u)
#define CAN_RX_MAILBOX_2_SHIFT      (4u)
#define CAN_RX_MAILBOX_3_SHIFT      (8u)
#define CAN_RX_MAILBOX_4_SHIFT      (16u)
#define CAN_RX_MAILBOX_5_SHIFT      (32u)
#define CAN_RX_MAILBOX_6_SHIFT      (64u)
#define CAN_RX_MAILBOX_7_SHIFT      (128u)
#define CAN_RX_MAILBOX_8_SHIFT      (256u)
#define CAN_RX_MAILBOX_9_SHIFT      (512u)
#define CAN_RX_MAILBOX_10_SHIFT      (1024u)
#define CAN_RX_MAILBOX_11_SHIFT      (2048u)
#define CAN_RX_MAILBOX_12_SHIFT      (4096u)
#define CAN_RX_MAILBOX_13_SHIFT      (8192u)
#define CAN_RX_MAILBOX_14_SHIFT      (16384u)
#define CAN_RX_MAILBOX_15_SHIFT      (32768u)

//#define MODULE_0
#define MODULE_1
//#define MODULE_2
//#define MODULE_3
//#define MODULE_4
//#define MODULE_5
//#define MODULE_6
//#define MODULE_7
#define AMR (0x001FFFF9) /* AMR (Bit[31;21]is Mask set to 0 for ID, Bit[20:3]=1, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
#define ACR_ORIENTATION (0x10000000)
//#define MODULE_T

int8 connh[4];
int8 connOri[4];


#ifdef MODULE_0
    #define MODULE_NUMBER (0)
    #define PHASE_ID (0x001)
    #define HORMONE_ID (0x007)
    #define ACR_PHASE0 (0x0fe00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00400000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x0fe00000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x01000000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000) 
#endif

#ifdef MODULE_1
    #define MODULE_NUMBER (1)
    #define PHASE_ID (0x002)
    #define HORMONE_ID (0x008)
    #define ACR_PHASE0 (0x00200000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00600000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x00e00000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x01200000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif

#ifdef MODULE_2
    #define MODULE_NUMBER (2)
    #define PHASE_ID (0x003)
    #define HORMONE_ID (0x009)
    #define ACR_PHASE0 (0x00400000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00800000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01000000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x01400000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000)    
#endif
#ifdef MODULE_3
    #define MODULE_NUMBER (3)
    #define PHASE_ID (0x004)
    #define HORMONE_ID (0x00a)
    #define ACR_PHASE0 (0x00600000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00a00000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01200000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x01600000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif
#ifdef MODULE_4
    #define MODULE_NUMBER (4)
    #define PHASE_ID (0x005)
    #define HORMONE_ID (0x00b)
    #define ACR_PHASE0 (0x00800000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x00c00000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01400000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x01800000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif
#ifdef MODULE_5
    #define MODULE_NUMBER (5)
    #define PHASE_ID (0x006)
    #define HORMONE_ID (0x00c)
    #define ACR_PHASE0 (0x00a00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x01a00000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01600000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x01e00000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif
#ifdef MODULE_6
    #define MODULE_NUMBER (6)
    #define PHASE_ID (0x00d)
    #define HORMONE_ID (0x00f)
    #define ACR_PHASE0 (0x00c00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x01c00000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01800000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x02000000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif

#ifdef MODULE_7
    #define MODULE_NUMBER (7)
    #define PHASE_ID (0x00e)
    #define HORMONE_ID (0x010)
    #define ACR_PHASE0 (0x01a00000) /* ACR (Bit[31;21]is ID=0x001, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A, refer to faq document*/
    #define ACR_PHASE1 (0x0fe00000)
    #define ACR_PHASE2 (0x0fe00000)
    #define ACR_PHASE3 (0x0fe00000)
    #define ACR_HORMONE0 (0x01e00000) /* ACR (Bit[31;21]is ID=0x003, Bit2(IDE)=0, Bit1  RTR=0,Bit0=N/A*/
    #define ACR_HORMONE1 (0x0fe00000)
    #define ACR_HORMONE2 (0x0fe00000)
    #define ACR_HORMONE3 (0x0fe00000)  
#endif

void configureCANID(void);    
    
