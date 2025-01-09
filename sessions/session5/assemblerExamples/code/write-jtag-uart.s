/* from https://bohr.wlu.ca/cp216/labs/08_io/write_demo.s
-------------------------------------------------------
write_demo.s
-------------------------------------------------------
Author:  David Brown  // modified by Craig Gallen
ID:      123456789
Email:   dbrown@wlu.ca
Date:    2024-02-21
-------------------------------------------------------
Uses a subroutine to print strings to the UART.
-------------------------------------------------------
*/
.org 0x1000  // Start at memory location 1000
.text        // Code section
.global _start
_start:

ldr r4, =First
bl  WriteString
ldr r4, =Second
bl  WriteString
ldr r4, =Third
bl  WriteString
ldr r4, =Last
bl  WriteString

_stop:
b    _stop

// Subroutine constants
.equ UART_BASE, 0xff201000  // UART base address

WriteString:
/*
-------------------------------------------------------
Prints a null terminated string to the UART.
-------------------------------------------------------
Parameters:
  r4 - address of string to print
Uses:
  r0 - holds character to print
  r1 - address of UART
-------------------------------------------------------
*/
stmfd sp!, {r0, r1, r4}  // preserve temporary registers on stack
                         // NOTE this is an alternative instruction to PUSH. See https://stackoverflow.com/questions/8236959/what-are-sp-stack-and-lr-in-arm
ldr   r1, =UART_BASE     // get address of UART

wsLOOP:
ldrb  r0, [r4], #1       // load a single byte from the string
                         // ldrb r0,[r4],#1 means take the value in r0, use it as an address to read a byte from, put the byte in r1 and then add 1 to r0. It is the same as
                         // ldrb r0,[r4]
                         // add r4,r4,#1
                         // just in one instruction instead of two :)
cmp   r0, #0
beq   _WriteString       // stop when the null character 0x0 is found which is the end of the string.
str   r0, [r1]           // copy the character to the UART DATA field.
b     wsLOOP
_WriteString:
ldmfd sp!, {r0, r1, r4}  // recover temporary registers from the stack.
bx    lr                 // return from subroutine

.data
.align
// The list of strings
First:
.asciz  "First string\n"
Second:
.asciz  "Second string\n"
Third:
.asciz  "Third string\n"
Last:
.asciz  "Last string\n"
_Last:    // End of list address

.end
