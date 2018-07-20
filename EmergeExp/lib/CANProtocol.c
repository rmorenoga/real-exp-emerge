#include <..\lib\CANProtocol.h>

uint8 id = -1;
int connh[] = {-1,-1,-1,-1};

void sendPhase(float phase){
    
    uint8 bytePhase[4];
    
    float_encode(phase,bytePhase);
    
    CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_phaseData,id);
	CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_phaseData,bytePhase[0]);
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_phaseData,bytePhase[1]);
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_phaseData,bytePhase[2]);
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_phaseData,bytePhase[3]);
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_phaseData,0u);
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_phaseData,0u);
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_phaseData,0u);
    
    CAN_SendMsgphaseData();
}

void receivePhase(float * phase){
    
    uint8 i;
    uint8 senderId = -1;
    uint8 bytePhase[4];
    float receivedPhase = 0.0;
   
    senderId = CAN_RX_DATA_BYTE1(CAN_RX_MAILBOX_phaseData);
    bytePhase[0] = CAN_RX_DATA_BYTE2(CAN_RX_MAILBOX_phaseData);
    bytePhase[1] = CAN_RX_DATA_BYTE3(CAN_RX_MAILBOX_phaseData);
    bytePhase[2] = CAN_RX_DATA_BYTE4(CAN_RX_MAILBOX_phaseData);
    bytePhase[3] = CAN_RX_DATA_BYTE5(CAN_RX_MAILBOX_phaseData);
    
    receivedPhase = float_decode(bytePhase);
    
    for (i=0;i<4;i++){
        if (connh[i] == senderId){
            phase[i+1] = receivedPhase;
        }      
    }
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

