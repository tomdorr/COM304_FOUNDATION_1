// readButtons1.c
// this program reads the 3 buttons and outputs their values continuously
// to compile and run:
// gcc -o writeleds1 writeleds1.c -l wiringPi
// ./writeleds1

#include <wiringPi.h> // Include WiringPi library (see https://github.com/WiringPi/WiringPi/blob/master/wiringPi/wiringPi.h)
#include <stdio.h>  // include standard IO library ( for printf)
#include <unistd.h> // needed for sleep function

int main(void) {
  // # NOTE GP21 on the gertboard is actually GPIO (BCM) 27
  int ledGpioPins[] = {22, 27, 18, 17, 15, 14, 11, 10, 9};
  int numberOfPins = sizeof(ledGpioPins)/ sizeof(int);


  // uses BCM numbering of the GPIOs and directly accesses the GPIO registers.
  wiringPiSetupGpio();

  // pin mode ..(INPUT, OUTPUT, PWM_OUTPUT, GPIO_CLOCK)
  // set gpio pins to output (need to set to input first)
  // then set pins to '0' or LOW

  for(int i = 0; i < numberOfPins; i++) {
     printf("setting up pin ledGpioPins[%d]=%d \n",i,ledGpioPins[i]);
     pinMode(ledGpioPins[i], INPUT);
     pinMode(ledGpioPins[i], OUTPUT);
     digitalWrite(ledGpioPins[i], 0);
  }

  // now cycle through the pins turning off and on with a delay
  while (1){
      for(int i = 0; i < numberOfPins; i++) {
        printf("toggling pin ledGpioPins[%d]=%d \n",i,ledGpioPins[i]);
        digitalWrite(ledGpioPins[i], 1);
        sleep(1); // format is sleep(x); where x is # of seconds.
        digitalWrite(ledGpioPins[i], 0);
      }
  }

}