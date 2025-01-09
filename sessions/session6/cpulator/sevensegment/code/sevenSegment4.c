// sevenSegment4.c
// Example showing writing 7 segment numbers one display. Correct order
//
// Craig Gallen 2024

#include <stdio.h>
    
#define ADDR_7SEG1 ((volatile long *) 0xFF200020)
#define ADDR_7SEG2 ((volatile long *) 0xFF200030)
    
int main() {
    
    // reset leds

    *ADDR_7SEG1 = 0; // address of lower 4 7 seg digits
    *ADDR_7SEG2 = 0; // address of upper 4 7 seg digits

    // scans through each of the LEDs and outputs the 7 segment number
    for (unsigned int i=0; i<=0xffffffff; i++) {
       printf("number: %08X\n", i);
        // printf formatting %08X formatting 8 hex digits
       hexIntegerToLeds(i);
    }


}

void hexIntegerToLeds(unsigned int n){
    
     unsigned int sevensegment[] = {
          //7 seg hex   0...........1...........2...........3...........4
                        0x0000003f, 0x00000006, 0x0000005b, 0x0000004f, 0x00000066,
          //7 seg hex   5...........6...........7...........8...........9
                        0x0000006d, 0x0000007d, 0x00000007, 0x0000007f, 0x0000006f, 
          //7 seg hex   A...........B...........C...........D...........E...........F
                        0x00000077, 0x0000007c, 0x00000039, 0x0000005e, 0x00000079, 0x00000071
                        };



    // lower 4 seven segments - each digits is 4 (0-f) bits of number
    
    unsigned int sevenseg1 = 0; // seven segment numbers to put in the register
    
    for (int i=0; i<4; i++){
        unsigned int hex = n >> (12 - i * 4);  // shift number 4 for each digit

        hex = hex & 0x000000f; // bitwise AND see https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
        printf("   i:%X hex:%X ",i, hex);
        
        unsigned int segments = sevensegment[hex];
        printf(" segmentsBits: %X ",segments);
        
        sevenseg1 = sevenseg1 << 8 ;
        printf(" sevenseg1Bits1: %X ",sevenseg1);
        
        sevenseg1 = sevenseg1 | segments;
        printf(" sevenseg1Bits2: %X \n",sevenseg1);
    }
    
    printf("display bits: %X\n",sevenseg1);
    
    *ADDR_7SEG1 = sevenseg1;

}
    