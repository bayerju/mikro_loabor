#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int set_bit(int num, int position)
{
	int mask = 1 << position; // setting the new bit at the given position.
	return num | mask; // bitwise or operator. It keeps all the bits from the number and sets the bits from the mask.
}

int getBit(int num, int position) {
    int mask =  1 << position;
    int masked_n = num & mask;
    int thebit = masked_n >> position;
    return thebit;
}

int setSingleData(int *aData, int16_t binary, int offset) {
    int i;
    for (i = 0; i < sizeof(binary) * 8; i++) {
        aData[i + offset] = getBit(binary, sizeof(binary) * 8 - 1 - i);
    }
    return 0;
}

int setSingleData_u(int *aData, uint8_t binary, int offset) {
    int i;
    for (i = 0; i < sizeof(binary) * 8; i++) {
        aData[i + offset] = getBit(binary, sizeof(binary) * 8 - 1 - i);
    }
    return 0;
}

int setData(int *aData, int16_t firstBinary, int16_t secondBinary, uint8_t thirdBinary) {
    int i;
    setSingleData(aData, firstBinary, 0);
    setSingleData(aData, secondBinary, 16);
    setSingleData_u(aData, thirdBinary, 32);
//     int size = sizeof(firstBinary);
//    for (i = 0; i < sizeof(firstBinary) * 8; i++) {
        
//         aData[i] = getBit(firstBinary, i);
//     }
//     for (i ; i < sizeof(firstBinary) * 8 + sizeof(secondBinary) * 8; i++) {
//         aData[i] = getBit(secondBinary, i);
//     }
//     for(i; i < sizeof(firstBinary) * 8 + sizeof(secondBinary) * 8 + sizeof(thirdBinary) * 8; i++) {
//         aData[i] = getBit(thirdBinary, i);
//     }
    return 0;
}

int main(int argc, char** argv) {

    int16_t RH_binary = 0b0000001010001100;
    int16_t T_binary = 0b0000000101011111;
    uint8_t checksum_binary = 0b11101110;
    
    int data[40] = {0};
    int i;
    int16_t temp = 0, hum = 0;
    uint8_t checksum = 0;
    setData(data, RH_binary, T_binary, checksum_binary);
    // for (i = 0; i < 40; i++) {
    //     if (i % 2 != 0)
    //         data[i] = 1;
    //     else
    //         data[i] = 0;
    // }
    for (i = 0; i < 40; i++) {
        if (data[i] == 1 && i < 16) {
            hum = set_bit(hum, 15-i);
        }
        if (data[i] == 1 && i >= 16 && i < 32) {
            temp = set_bit(temp, 15 - i - 16);
        }
        if (data[i] == 1 && i >= 32 && i < 40) {
            checksum = set_bit(checksum, 15 - i - 32); // check because checksum is 16 bits and
                                       // we only write 8 bits
        }
    }


    return (0);
}
