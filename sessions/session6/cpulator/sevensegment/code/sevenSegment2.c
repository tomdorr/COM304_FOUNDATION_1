// sevenSegment2.c
// Example showing writing 7 segment numbers to all of the displays
// Note set 'show 8 digits' on display
//
// Craig Gallen 2024

#include <stdio.h>
    
#define ADDR_7SEG1 ((volatile long *) 0xFF200020)
#define ADDR_7SEG2 ((volatile long *) 0xFF200030)
    

int main() {

    // scans through each of the LEDs and outputs the 7 segment number
    for (unsigned int led=0; led<=7; led++) {
        for (unsigned int i=0; i<=0x0f; i++) {
             printf("led: %X number: %X\n", led, i);
             hexByteToLed(i, led);
        }
            
    }

}

void hexByteToLed(int n, int led){
    
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
    
    switch (led) {
      case 0:
        segments = sevensegment[n];
        printf("%X",segments);
        *ADDR_7SEG1 = segments;
        break;
      case 1:
        segments = sevensegment[n]<<8;
        printf("%X",segments);
        *ADDR_7SEG1 = segments;
        break;
      case 2:
        segments = sevensegment[n]<<16;
        printf("%X",segments);
        *ADDR_7SEG1 = segments;
        break;
      case 3:
        segments = sevensegment[n]<<24;
        printf("%X",segments);
        *ADDR_7SEG1 = segments;
        break;
      case 4:
        segments = sevensegment[n];
        printf("%X",segments);
        *ADDR_7SEG2 = segments;
        break;
      case 5:
        segments = sevensegment[n]<<8;
        printf("%X",segments);
        *ADDR_7SEG2 = segments;
        break;
      case 6:
        segments = sevensegment[n]<<16;
        printf("%X",segments);
        *ADDR_7SEG2 = segments;
        break;
      case 7:
        segments = sevensegment[n]<<24;
        printf("%X",segments);
        *ADDR_7SEG2 = segments;
        break;

      default:
       // code block
      }
    
}
    