// sevenSegment1.c
// Example showing writing 7 segment numbers one display.
//
// Craig Gallen 2024

#include <stdio.h>
    
#define ADDR_7SEG1 ((volatile long *) 0xFF200020)
#define ADDR_7SEG2 ((volatile long *) 0xFF200030)
    
int main() {

    // scans through each of the LEDs and outputs the 7 segment number
    for (unsigned int i=0; i<=0x0f; i++) {
       printf("number: %02X ", i);
        // printf formatting %02X 
        // X indicates using hex
        // The 0 indicates what you are padding with and the 2 shows the width of the hex number.
        //  If you use "%02x this would pad zeros for numbers in the ones column. E.g., 06 instead of 6.
       hexByteToLed(i);
    }


}

void hexByteToLed(int n){
    
     unsigned int sevensegment[] = {
          //7 seg hex   0...........1...........2...........3...........4
                        0x0000003f, 0x00000006, 0x0000005b, 0x0000004f, 0x00000066,
          //7 seg hex   5...........6...........7...........8...........9
                        0x0000006d, 0x0000007d, 0x00000007, 0x0000007f, 0x0000006f, 
          //7 seg hex   A...........B...........C...........D...........E...........F
                        0x00000077, 0x0000007c, 0x00000039, 0x0000005e, 0x00000079, 0x00000071
                        };

     // bits 0000110 will activate segments 1 and 2 
     //*ADDR_7SEG1 = 0x00000006; 
     //*ADDR_7SEG2 = 0;
    
    *ADDR_7SEG1 = 0;
    *ADDR_7SEG2 = 0;
    unsigned int segments = 0;
    
    segments = sevensegment[n];
    printf("seven segment bits: %02X\n",segments);
    
    *ADDR_7SEG1 = segments;

}