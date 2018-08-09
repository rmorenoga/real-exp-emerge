#include <..\lib\CANProtocol.h>

uint8 receivedFlags = 0x00; //Flags: bit0(0x01):phaseBuffer1 bit1(0x02):phaseBuffer2 bit2(0x04):phaseBuffer3 bit3(0x08):phaseBuffer4
                            //Flags: bit4(0x10):hormoneBuffer1 bit5(0x20):hormoneBuffer2 bit6(0x40):hormoneBuffer3 bit7(0x80):hormoneBuffer4
float phaseBuffer[4] = {0};
uint8 hormBuffer0[HORM_BUFFER_SIZE][6] ={0};
int8 buffercount[4] = {0};

void sendPhase(float phase){
    
    uint8 bytePhase[4];
    
    float_encode(phase,bytePhase);
    
	CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_phaseOwn,bytePhase[0]);
    CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_phaseOwn,bytePhase[1]);
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_phaseOwn,bytePhase[2]);
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_phaseOwn,bytePhase[3]);
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_phaseOwn,0u);
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_phaseOwn,0u);
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_phaseOwn,0u);
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_phaseOwn,0u);
    
    
    CAN_SendMsgphaseOwn();
}

void sendHormone(uint8 horm[]){
    
    CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_phaseOwn,horm[0]);
	CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_phaseOwn,horm[1]);
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_phaseOwn,horm[2]);
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_phaseOwn,horm[3]);
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_phaseOwn,horm[4]);
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_phaseOwn,horm[5]);
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_phaseOwn,0u);
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_phaseOwn,0u);

    CAN_SendMsghormoneOwn();
    
}


void receivePhase(uint8 sender){
    
    uint8 bytePhase[4];
   
    bytePhase[0] = CAN_RX_DATA_BYTE1(CAN_RX_MAILBOX_phaseData0);
    bytePhase[1] = CAN_RX_DATA_BYTE2(CAN_RX_MAILBOX_phaseData0);
    bytePhase[2] = CAN_RX_DATA_BYTE3(CAN_RX_MAILBOX_phaseData0);
    bytePhase[3] = CAN_RX_DATA_BYTE4(CAN_RX_MAILBOX_phaseData0);
    
    switch(sender)
        {
        case 0u : 
            phaseBuffer[0] = float_decode(bytePhase);
            receivedFlags |= 0x01; 
            break;
        default:
            break;
        }
}

void readPhaseBuffers(float phase[]){
    
    uint8 shift = 0x01u;
    uint8 bufferNumber;
    
    for (bufferNumber = 0;bufferNumber<4;bufferNumber++){
        if((receivedFlags & shift) != 0u){
            phase[bufferNumber+1] = phaseBuffer[0];           
        }
        shift <<= 1u;
    }
    receivedFlags &= 0xF0;  //Clear phase received flags
}

void receiveHormone(uint8 sender){
    
    uint8 receivedHormone[6];
    int8 i;
    
    receivedHormone[0] = CAN_RX_DATA_BYTE1(CAN_RX_MAILBOX_hormoneData0);
    receivedHormone[1] = CAN_RX_DATA_BYTE2(CAN_RX_MAILBOX_hormoneData0);
    receivedHormone[2] = CAN_RX_DATA_BYTE3(CAN_RX_MAILBOX_hormoneData0);
    receivedHormone[3] = CAN_RX_DATA_BYTE4(CAN_RX_MAILBOX_hormoneData0);
    receivedHormone[4] = CAN_RX_DATA_BYTE5(CAN_RX_MAILBOX_hormoneData0);
    receivedHormone[5] = CAN_RX_DATA_BYTE6(CAN_RX_MAILBOX_hormoneData0);
    
    switch(sender)
        {
        case 0u : 
            if(buffercount[0] < HORM_BUFFER_SIZE){
                for(i=0;i<6;i++){
                    hormBuffer0[buffercount[0]][i] = receivedHormone[i]; 
                }
                buffercount[0]++;
            }
            receivedFlags |= 0x10; 
            break;
        default:
            break;
        } 
}

void readHormoneBuffers(void){
    int8 i;
    for (i = 0; i < 4; i++){
        buffercount[i] = 0;    
    }
    receivedFlags &= 0x0F;
}

void float_encode(float p_value, uint8 * p_encoded_data){
    
    union { 
        float float_val;
        uint8 char_val[4];
    }encoder;

    encoder.float_val = p_value;
    p_encoded_data[0] = encoder.char_val[0];
    p_encoded_data[1] = encoder.char_val[1];
    p_encoded_data[2] = encoder.char_val[2];
    p_encoded_data[3] = encoder.char_val[3];
}

float float_decode(uint8 p_encoded_data[]){
    
    union { 
        float float_val;
        uint8 char_val[4];
    }encoder;

    encoder.char_val[0] = p_encoded_data[0];
    encoder.char_val[1] = p_encoded_data[1];
    encoder.char_val[2] = p_encoded_data[2];
    encoder.char_val[3] = p_encoded_data[3];
 
    return(encoder.float_val);
}



//WHY DOESN'T THIS WORK?????
// unsigned char part1;
// unsigned char part2;
// unsigned char part3;
// unsigned char part4;

// float *float_ptr1;
// float *float_ptr2;

// float fl = 0.25;
// float fl2 = 0.0;




// int main(void) {
//   float_ptr1 = &fl;
//   float_ptr2 = &fl2;

//   part1 = *float_ptr1++;
//   part2 = *float_ptr1++;
//   part3 = *float_ptr1++;
//   part4 = *float_ptr1;

//   *float_ptr2++ = part1;
//   *float_ptr2++ = part2;
//   *float_ptr2++ = part3;
//   *float_ptr2 = part4;

//   printf("Hello\n");
//   printf("%.6f", fl2);

