// simple7seg1.s
// https://www-ug.eecg.utoronto.ca/desl/nios_devices_SoC/ARM/dev_7segs.html
// this example displays 1 on first 7 segment display. Use the binary to work out which bits control which segment of display

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
  ldr r1, =#0b0000110       // bits 0b0000110 will activate segments 1 and 2 (note binary)
                            // (you could use hex   ldr r1, =#0x00000006)
                             
  str r1, [r0]              // Write to first 7-seg display register (lower 4 numbers)
  ldr r0, =ADDR_7SEG2
  ldr r1, =#0b0000000       // Write 0 to upper registers - turns off all segments
  str r1, [r0]              // Write to second 7-seg display register (upper 2 numbers)