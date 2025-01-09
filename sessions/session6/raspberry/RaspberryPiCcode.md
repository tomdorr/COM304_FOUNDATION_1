[Main Menu](../../README.md) | [session6](../../session6/) | [Code on Raspberry Pi](../raspberry/RaspberryPiCcode.md)

# Raspberry PI Examples

Having worked with C and Assembler on the CPUlator, we are now going to try doing creating some simple programs working with the Gertboard on the Raspberry Pi.

First make sure you have completed the Gertboard experiments with WiringPi covered in [session 3](../../session3).

Connect up the Gertboard with the same wiring used previously.

You need to checkout the code onto the PI and then run the examples locally on the device.

## Assembly examples

[Assembly Examples](../raspberry/assembly/README.md) 
Provides some very low level examples for GPIO assembly code without using any additional libraries.

## C Code Examples

The C code examples provide C code equivalents to the bash scripts which work with WiringPi in [session 3](../../session3)

### C Example 1 Input

[readbuttons1.c](../../session4/code/readbuttons1.c) reads the 3 Gertbord buttons and prints an output.

This is similar functionality to [session 3 testShellScript-inputs1.sh](../../session3/code/testShellScript-inputs1.sh)

To compile use
```
cd code
gcc -o readbuttons1 readbuttons1.c -l wiringPi
```

This command uses gcc to compile readButtons.c and link it with the pre installed  WiringPi library.

Note the `#include <wiringPi.h>` directive in the C code which pulls in references to the library.

See also [wiringPi.h](https://github.com/WiringPi/WiringPi/blob/master/wiringPi/wiringPi.h) on github.

To run use
```
./readbuttons
```
You can also see the intermediate Assembly code produced by the compiler if you use the command

```
gcc -S -fverbose-asm -O2 readButtons1.c 
```
This will generate an assembler file called `readButtons1.s` with document references to the original `C` code.


### C Example 2 Output

[writeleds1.c](../../session4/code/writeleds1.c) cycles through LEDs on the Gertbord.

This is similar functionality to [session 3 testShellScript-outputs1.sh](../../session3/code/testShellScript-outputs1.sh)

To compile use
```
cd code
gcc -o writeleds1 writeleds1.c -l wiringPi
```

