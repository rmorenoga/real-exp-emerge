#include <..\lib\CANProtocol.h>

uint8 receivedFlags = 0x00u; //Flags: bit0(0x01):phase1 bit1(0x02):phase2 bit2(0x04):phase3 bit3(0x08):phase4
                            //Flags: bit4(0x10):hormone1 bit5(0x20):hormone2 bit6(0x40):hormone3 bit7(0x80):hormone4
//uint8 hormBuffer0[HORM_BUFFER_SIZE][HORM_SIZE] = {{1u,2u,3u,4u,5u,6u},{7u,8u,9u,10u,11u,12u}};
int8 buffercount[4] = {0u,0u,0u,0u};
uint8 dummy = 0u;

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
    
    
    CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_hormoneOwn,horm[0]);
	CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_hormoneOwn,horm[1]);
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_hormoneOwn,horm[2]);
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_hormoneOwn,horm[3]);
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_hormoneOwn,horm[4]);
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_hormoneOwn,horm[5]);
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_hormoneOwn,0u);
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_hormoneOwn,0u);

    CAN_SendMsghormoneOwn();
    
}

/*
void sendHormone(uint8 horm[]){
    
    if(dummy > 2u){
        dummy = 0u;
    }
    
    CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_hormoneOwn,0x01+dummy);
	CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_hormoneOwn,0x02+dummy);
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_hormoneOwn,0x03+dummy);
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_hormoneOwn,0x04+dummy);
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_hormoneOwn,0x05+dummy);
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_hormoneOwn,0x06+dummy);
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_hormoneOwn,0x07+dummy);
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_hormoneOwn,0x08+dummy);

    dummy++;
        
    CAN_SendMsghormoneOwn();
    
}
*/
void receivePhase(uint8 sender, float phase[]){
    
    uint8 bytePhase[4];
   
    bytePhase[0] = CAN_RX_DATA_BYTE1(sender);
    bytePhase[1] = CAN_RX_DATA_BYTE2(sender);
    bytePhase[2] = CAN_RX_DATA_BYTE3(sender);
    bytePhase[3] = CAN_RX_DATA_BYTE4(sender);
    
    phase[sender+1] = float_decode(bytePhase);
 /*   
    switch(sender){
        case 0u : 
            phase[1] = float_decode(bytePhase);
            break;
        case 1u : 
            phase[2] = float_decode(bytePhase);
            break;
        case 2u : 
            phase[3] = float_decode(bytePhase);
            break;
        default:
            break;
    }*/
}

/* Deprecated
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
            receivedFlags |= 0x01u; 
            break;
        default:
            break;
        }
}

void readPhaseBuffers(float phase[]){
    
    uint8 shift = 0x01u;
    uint8 bufferNumber;
    
    for (bufferNumber = 0;bufferNumber < 4;bufferNumber++){
        if((receivedFlags & shift) != 0u){
            phase[bufferNumber+1] = phaseBuffer[0];           
        }else{
            phase[bufferNumber+1] = -1;
        }
        shift <<= 1u;
    }
    receivedFlags &= 0xF0u;  //Clear phase received flags
}
*/

/*
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
                for(i=0;i < 6;i++){
                    hormBuffer0[buffercount[0]][i] = receivedHormone[i]; 
                }
                buffercount[0]++;
            }
            receivedFlags |= 0x10u; 
            break;
        default:
            break;
        } 
}
*/

void receiveHormoneFull(uint8 sender){
    
    if (sender == CAN_RX_MAILBOX_hormoneData00 || sender == CAN_RX_MAILBOX_hormoneData01 || sender == CAN_RX_MAILBOX_hormoneData02){
        //readHormoneMailBox(sender,hormBuffer0);
        hormBuffer0[buffercount[0]][0] = CAN_RX_DATA_BYTE1(sender);
        hormBuffer0[buffercount[0]][1] = CAN_RX_DATA_BYTE2(sender);
        hormBuffer0[buffercount[0]][2] = CAN_RX_DATA_BYTE3(sender);
        hormBuffer0[buffercount[0]][3] = CAN_RX_DATA_BYTE4(sender);
        hormBuffer0[buffercount[0]][4] = CAN_RX_DATA_BYTE5(sender);
        hormBuffer0[buffercount[0]][5] = CAN_RX_DATA_BYTE6(sender);
        
        buffercount[0]++;
    } /* else if(sender == CAN_RX_MAILBOX_hormoneData10 || sender == CAN_RX_MAILBOX_hormoneData11 || sender == CAN_RX_MAILBOX_hormoneData12) {
        
        hormBuffer1[buffercount[1]][0] = CAN_RX_DATA_BYTE1(sender);
        hormBuffer1[buffercount[1]][1] = CAN_RX_DATA_BYTE2(sender);
        hormBuffer1[buffercount[1]][2] = CAN_RX_DATA_BYTE3(sender);
        hormBuffer1[buffercount[1]][3] = CAN_RX_DATA_BYTE4(sender);
        hormBuffer1[buffercount[1]][4] = CAN_RX_DATA_BYTE5(sender);
        hormBuffer1[buffercount[1]][5] = CAN_RX_DATA_BYTE6(sender);
        
        buffercount[1]++;
    } else if(sender == CAN_RX_MAILBOX_hormoneData20 || sender == CAN_RX_MAILBOX_hormoneData21 || sender == CAN_RX_MAILBOX_hormoneData22) {
        
        hormBuffer2[buffercount[2]][0] = CAN_RX_DATA_BYTE1(sender);
        hormBuffer2[buffercount[2]][1] = CAN_RX_DATA_BYTE2(sender);
        hormBuffer2[buffercount[2]][2] = CAN_RX_DATA_BYTE3(sender);
        hormBuffer2[buffercount[2]][3] = CAN_RX_DATA_BYTE4(sender);
        hormBuffer2[buffercount[2]][4] = CAN_RX_DATA_BYTE5(sender);
        hormBuffer2[buffercount[2]][5] = CAN_RX_DATA_BYTE6(sender);
        
        buffercount[2]++;
    } else if(sender == CAN_RX_MAILBOX_hormoneData30 || sender == CAN_RX_MAILBOX_hormoneData31 || sender == CAN_RX_MAILBOX_hormoneData32) {
        
        hormBuffer3[buffercount[3]][0] = CAN_RX_DATA_BYTE1(sender);
        hormBuffer3[buffercount[3]][1] = CAN_RX_DATA_BYTE2(sender);
        hormBuffer3[buffercount[3]][2] = CAN_RX_DATA_BYTE3(sender);
        hormBuffer3[buffercount[3]][3] = CAN_RX_DATA_BYTE4(sender);
        hormBuffer3[buffercount[3]][4] = CAN_RX_DATA_BYTE5(sender);
        hormBuffer3[buffercount[3]][5] = CAN_RX_DATA_BYTE6(sender);
        
        buffercount[3]++;
    }*/
  }  
    
void readHormoneBuffers(void){
    int8 i;
    for (i = 0; i < 4; i++){
        buffercount[i] = 0;    
    }
    receivedFlags &= 0x0Fu;
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

