// readButtons1.c
// this program reads the 3 buttons and outputs their values continuously
// to compile and run:
// gcc -o readButtons1 readButtons1.c -l wiringPi
// ./readButtons1

#include <wiringPi.h> // Include WiringPi library
#include <stdio.h>  // include standard IO library ( for printf)

int main(void)
{
  // uses BCM numbering of the GPIOs and directly accesses the GPIO registers.
  wiringPiSetupGpio();

  // pin mode ..(INPUT, OUTPUT, PWM_OUTPUT, GPIO_CLOCK)
  // set pins 25,24,23 to input
  pinMode(25, INPUT);
  pinMode(24, INPUT);
  pinMode(23, INPUT);

  // pull up/down mode (PUD_OFF, PUD_UP, PUD_DOWN) => up
  // set pull up on gpio pins 25,24,23
  pullUpDnControl(25, PUD_UP);
  pullUpDnControl(24, PUD_UP);
  pullUpDnControl(23, PUD_UP);

  // loop forever reading and writing state of pins
  while (1) {
     // get state of pin 25,24,23
     int button1 = digitalRead(25);
     int button2 = digitalRead(24);
     int button3 = digitalRead(23);

     if (HIGH == button1) {
       printf("button1  hi  ");
     } else {
       printf("button1  low ");
     }

     if (HIGH == button2) {
       printf("button2  hi  ");
     } else {
       printf("button2  low ");
     }

     if (HIGH == button3) {
       printf("button3  hi ");
     } else {
       printf("button3  low ");
     }
     // \r moves cursor to the beginning of the line instead moving to a new line  \n
     printf("\r");
  }
}
