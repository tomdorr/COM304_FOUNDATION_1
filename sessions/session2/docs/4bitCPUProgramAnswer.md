[session2](../../session2/) | [Boolean Algebra And Logic Gates](../docs/booleanAlgebraAndLogicGates.md) | [4 bit cpu programming answer](../docs/4bitCPUProgramAnswer.md)

# 4 bit cpu programming answer

### Program in cpu rom 

|Address      | Value (binary) | Value (hex)  | op code    | description |
|:------------|:-------------- |:------------ |:-----------|:------------|
|0000 (0x00)  | 0010           | 0x02         | MOV 0x01   | loads 1 to A |
|0001 (0x01)  | 0001           | 0x01         |            | operand (value of MOV) |
|0010 (0x02)  | 0011           | 0x03         | SWP        | swaps register A and B |
|0011 (0x03)  | 0100           | 0x04         | ADD        | adds B to A, saves in A|
|0100 (0x04)  | 0001           | 0x01         | OUT        | writes A to display |
|0101 (0x05)  | 1010           | 0x0A         | JMP 0x03   | jumps to address 0x03 0011|
|0110 (0x06)  | 0011           | 0x03         |            | operand (value of JMP) |
|0011 (0x07)  | 0000           | 0x00         |            | No Operation |

### Making the program count down instead of up

To make the program count down, change the program to subtract 1 each time.

Remember that to subtract, we just add a 2s compliment negative 1 number.

Change the value in ROM address 0001 to minus 1 = 1111