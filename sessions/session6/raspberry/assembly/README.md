[Main Menu](../../../README.md) | [session6](../../../session6/) | [Code on Raspberry Pi](../assembly/README.md)

# Example Assembler access to GPIO

## Introduction

This is an example of very low level Assembly programming where we are using the raw registers of the CPU to implement complex functionality with the GPIO. 

Usually, such programs are written in higher level languages such as C which are designed to make it easier to appreciate what a programmer is trying to achieve. 

However, all higher level languages are eventually translated into Assembler code through the compilation process and this will help you appreciate what libraries such as WiringPI are doing.

IO devices are usually mapped as addresses in memory.

In the Raspberry Pi, the GPIO has multiple registers, each mapped to an address relative to its base address.

There are many options for controlling the GPIO which you can see if you look at the [BCM2837 ARM Peripherals datasheet pages 90-104](https://cs140e.sergio.bz/docs/BCM2837-ARM-Peripherals.pdf)
 
In the Raspberry Pi 3, the base address of the GPIO in hex is 0x3f200000 (rpi3)

Each pin can be set as one of multiple functions (in, out, and other more complex functions) , and this is controlled by the GPIO Function Select register `GPFSEL1` which is located at the GPIO base address + 4

```
GPFSEL1        0x0004                       // GPIO Function Select 1
```

Pins can also be pulled up or down and this is controlled by the GPIO Pin Pull-up/down Enable register at GPIO base address + 0x0094

```
GPPUD          0x0094                       // GPIO Pin Pull-up/down Enable
```

Programming the GPIO using these registers is complex and error prone and is greatly simplified for programmers by libraries such as WiringPi.

It is, however, useful to see how GPIO programming would be done on a PI just using Assembler language.

## Button Example

The following assembler code example has been modified to work with the gertboard.

The program continuously reads the input state of a GPIO pin and outputs a text message counting down from 10 each time the pin changes state.

### setting up the gertboard

You will remember that we set up the gertboard so that pins GP25,GP24,GP23 are inputs connected to the 3 buttons. 

The configuration requires that the GPIO pull up is enabled for each button. 

In this example we will use PIN GP25 which is connected to LED 1 and Button 1

The pull up has to be set up before the program is run because the program does not (yet) have the ability to set the GPPUD register correctly.

In a Pi terminal, type

```
gpio -g mode 25 in
gpio -g mode 25 up
```
LED 1 should come on, and go off when button 1 is pressed.

### Running the Assembly code

Download this assembler code to the Pi and run the following commands

```
cd 32bitButton

make all
```

The `make` command uses the [makefile](../assembly/32bitButton/makefile) to give the gcc compiler instructions to assemble and link the code in the [button32.s](../assembly/32bitButton/button32.s), [gpioPinFSelect32.s](../assembly/32bitButton/gpioPinFSelect32.s) and [gpioPinRead32.s](../assembly/32bitButton/gpioPinRead32.s) files into an executable file called `button32`

After the build completes, you should have a new file in the called `button32` in the directory

Run this file using `./button32` and press the button, you should see the following output counting down each time the button is pressed.

After reaching 0, the program will terminate.

```
./button32
Counter: 9 
Counter: 8 
Counter: 7 
Counter: 6 
Counter: 5 
Counter: 4 
Counter: 3 
Counter: 2 
Counter: 1 
Counter: 0 

```

At this stage, we wouldn't expect you to understand the assembly code in detail but it is worth pointing out some key functionality in each of the files.

The [makefile](../assembly/32bitButton/makefile)  is a recipe for building the executable from multiple assembler files. 

[button32.s](../assembly/32bitButton/button32.s) is the main program. 
This calls routines defined in the other files.

At the start, the `button32` program needs to discover the memory address of the GPIO.

Remember that the virtual memory system gives each process its own virtual memory which is automatically mapped to the physical memory and virtual memory in the Pi's swap file.

The operating system needs to give processes permission to access hardware devices and it does this by mapping the peripheral's hardware address into the address space of the button32 process.

The program makes a [mmap](https://man7.org/linux/man-pages/man2/mmap.2.html) call  to the Pi operating system which then maps the real GPIO registers into the `button32` processe's memory space.

Next the program uses routines in [gpioPinFSelect32.s](../assembly/32bitButton/gpioPinFSelect32.s) to set up Pin 25 for input (PIN_BTN,25).
(Note that this could be extended to also set the pull up function).

Finally, the program uses [gpioPinRead32.s](../assembly/32bitButton/gpioPinRead32.s) to continuously read the state of the button.

Spend some time looking at the code to see if you can understand broadly how it is working.
However, you don't need to become an expert at this stage.

P.S. The original code for this example is from [https://github.com/elisa2995/RaspberryGPIO_LAB](https://github.com/elisa2995/RaspberryGPIO_LAB)  by Elisa Chiapponi Politecnico di Torino. See also her [youtube Raspberry Pi 3 - GPIO with ARM assembly](https://www.youtube.com/watch?v=k_40voY5WgE)



