 // sevenseg.s
 // this example loops through first 7 segment display with all possible numbers 0-f
 
 .equ ADDR_7SEG1, 0xFF200020
 .equ ADDR_7SEG2, 0xFF200030

 .text
 
  // clear led displays
  ldr r0, =ADDR_7SEG1
  ldr r1, =#0x00000000
  str r1, [r0] 
  ldr r0, =ADDR_7SEG2
  str r1, [r0] 

  restart:
  
  // zero index counter
  ldr r3, =#0

  // load address of 7seg list
  ldr r2, =sevenseg
  loop:
    // load from 7seg list
    
    // note ldr r1, [r2, r3] // doesn't work because each segment is 4 bytes in the array below.
    
    ldr r1, [r2, r3, LSL #2] // Read byte value from an address equal to sum of R2 and four times R3 (shift left R3 2 times)
    ldr r0, =ADDR_7SEG1
    str r1, [r0] // Write to first 7-seg display register
    add r3, #1
    cmp r3, #0x0f
    blt loop
    
    b restart
  
  
  .data
  
   sevenseg:  
     //7 seg hex   0...........1...........2...........3...........4
             .word 0x0000003f, 0x00000006, 0x0000005b, 0x0000004f, 0x00000066
     //7 seg hex   5...........6...........7...........8...........9
             .word 0x0000006d, 0x0000007d, 0x00000007, 0x0000007f, 0x0000006f 
     //7 seg hex   A...........B...........C...........D...........E...........F
             .word 0x00000077, 0x0000007c, 0x00000039, 0x0000005e, 0x00000079, 0x00000071
