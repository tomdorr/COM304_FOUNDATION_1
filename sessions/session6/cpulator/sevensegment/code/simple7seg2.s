// simple7seg2.s
// https://www-ug.eecg.utoronto.ca/desl/nios_devices_SoC/ARM/dev_7segs.html
// this example displays 7 segment number 6,5,4,3,2,1 on CPUlator 7 segment display

.text

  .equ ADDR_7SEG1, 0xFF200020
  .equ ADDR_7SEG2, 0xFF200030
  
  // clear led display
  ldr r0, =ADDR_7SEG1
  ldr r1, =#0x00000000
  str r1, [r0] 
  ldr r0, =ADDR_7SEG2
  str r1, [r0] 
  
  // display numbers
  ldr r0, =ADDR_7SEG1
  ldr r1, =#0x664f5b06      // 7 segment numbers 4,3,2,1 
  str r1, [r0]              // Write to first 7-seg display register (lower 4 numbers)
  ldr r0, =ADDR_7SEG2
  ldr r1, =#0x00007d6d      // 7 segment numbers 6,5 
  str r1, [r0]              // Write to second 7-seg display register (upper 2 numbers)