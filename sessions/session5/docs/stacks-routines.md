[Main Menu](../../README.md) | [session5](../../session5/) | [Subroutines and Stacks](../docs/stacks-routines.md)

# Subroutines and Stacks

A key concept in programming is the use of `subroutines` (also sometimes referred to as `functions`, `methods` or `procedures`), which are sections of code that perform a specific task and can be repeatedly called from many other parts of the main program.

In order to enter a subroutine, the processor must first save whatever it was doing (i.e. the registers which contain the current data) before `branching` to the start address of the new subroutine.

When the subroutine finishes, the processor must restore the previous state and branch back to the next instruction after the instruction which first caused the branch to the subroutine.

A `Stack` is a common mechanism which enables this behaviour.

`Stacks` are regions of memory which are reserved for storing subroutine states and passing variables between subroutines.
The top of the stack is pointed to by a `Stack Pointer`.

New data is added starting at the current location of the `Stack Pointer`.
The `Stack Pointer` is then incremented to point to the next free space.
This is called a `push` operation

Data can be removed from the stack by working back from the current location of the `stack pointer`.
This is called a `pop` operation.

In the ARM chip has three registers for handing program flow and the stack.

| name               | function                        |
|:-------------------|:--------------------------------|
|R13 (SP)            | Stack Pointer                   |
|R14 (LR)            | Link Register<BR>LR is link register used to hold the return address for a function call.                   |
|R15 (PC)            | Program Counter<BR> The PC value is altered as the core executes instructions. An explicit write to R15 by software will alter the program flow. |

The `Program Counter` always points to the next instruction to be executed. 
It is incremented as each instruction completes.

If a program wants to jump to a subroutine, a `branching` (or `conditional branching`) instruction causes the starting address of the subroutine to be loaded into the program counter.

See if you can follow the steps in the program in the following table.

|                     |Address | instruction       |  registers<BR>(after operation)                       | stack                                                   |(step) and explanation    |
|:--------------------|:-------|:------------------|:---------------------------------------------------|---------------------------------------------------------|---------------|
|                     |        |                   |PC=0x0001<BR>LR=undefined<BR>SP=0x1000<BR>R4=undefined   |0x1000=undefined                                       |(0) Initial state |
|main program         | 0x0001 | ldr r4, =1        |PC=0x0002<BR>LR=undefined<BR>SP=0x1000<BR>R4=0x0001 |0x1000=undefined                                            |(1)  LDR (LoaD Register) r4 with number 1             |
|                     | 0x0002 | bl 0x8ab0         |PC=0x8ab0<BR>LR=0x0003<BR>SP=0x1000<BR>R4=0x0001    |0x1000=undefined                                            |(2) BL (Branch to Label) to subroutine at address 0x8ab0<BR>Record next instruction address (0x0003) in LR |
|                     |        |                   |                                                    |<BR><BR><BR>                                             | (At this point the program jumps to the subroutine at 0x8ab0)              |
|                     | 0x0003 | bl 0x0003         |PC=0x0002<BR>LR=undefined<BR>SP=0x1000<BR>R4=0x0001 |0x1000=undefined                                          |(6) Resume main program<BR>(now in continuous loop indicating end of program) |      
|                     |        |                   |                                                    |<BR><BR><BR>                                                         |               |
|subroutine           | 0x8ab0 | push {r4,lr}     |PC=0x8ab1<BR>LR=0x0003<BR>SP=0x1003<BR>R4=0x0001    |0x1000=0x0001(r4)<BR>0x1002=0x0003(lr)<BR>0x1003=undefined|(3) Push r4 and LR onto stack              |
|                     |        |                   |                                                    |<BR><BR><BR>                                             |(4) Do n main instructions of subroutine before returning              |
|                     | 0x8ab0+n | pop {r4,pc}       |PC=0x0002<BR>LR=0x0003<BR>SP=0x1000<BR>R4=0x0001 |0x1000=undefined                                          |(5) Pop r4 off stack (0x0001)<BR>Pop LR off stack INTO PC which causes a branch back to the main program at 0x0003  |


Now extend your knowledge of subroutines by looking at [Interrupts](../docs/Interrupts.md) 

Armed with this knowledge, you should be able to understand better the examples in [Introduction to CPUlator](../docs/IntroToCPUlator.md).



