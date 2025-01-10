[Contents](../personal_learning_record/personal_learning_record.md) | [Segment 2 - Languages and OS](../personal_learning_record/segment2.md) 

# Segment 2 - Languages and Operating Systems

---
**NOTE**

For each of the sessions, bullet point notes on what you have learnt.
Use markdown references and / or links to resources you have used
use  screen shots and / or code samples as appropriate.

---

## session 5
In this session we looked at the different types of programming languages and how they interact with the computers hardware.

**Machine code and assembly code**

To start of we looked at topics covered in session 2 (combining logic to create a microprocessor). Binary that is read by the cpu is called machine code.

Assembly code is written in a way that is easy for humans to read and write.

An assembler can be used to translate the assembly code into machine code that can be run by processor.

**High level languages**

Java python and C are examples of high level languages

Compiled languages are typically faster and more efficient but require a compilation step and are platform-dependent.

Interpreted languages are more flexible, easier for rapid development, and are platform-independent but usually slower in execution.

**Open and closed source programs**

Open – people can access the original source code

Closed – original source code is not accessible

ARM assembler and C programming using CPUlator

CPUlator is a virtual simulator that can run and debug programs without the need of the hardware.

I used the lecture notes to get a better understanding of what the ARM 7 processor was and how it worked.

I used the code from the notes in the CPUlator to print “hello world!” In C

**Subroutines and stacks**

Subroutines are key to making programs easier to maintain and reuse.

The stack is an essential data structure used to manage function calls, local variables, and program state, following the LIFO principle

**Interrupts**

Interrupts are a key mechanism that allows CPUs to respond quickly and efficiently to external events, enabling real-time processing and multitasking.

I then went back to the assembler examples and put the examples in the CPUlator using the ARM 7 language. The first example produced the desired strings in the UART terminals. The second example was to produce images in the VGA

## session 6
In this session we started by investigating the structure of modern operating systems and then continued using assembly and C code on the CPUlator.

**operating systems**

Windows and Linux are both examples of operating systems.

Scheduling in an operating system ensures efficient use of the CPU and fair distribution of resources among competing processes. This gives the illusion that the cpu is multi tasking. Different scheduling programs are selected depending on the systems goals.

**Memory management**

Paging, segmentation and virtual memory are essential techniques for optimising system performance and ensuring that applications can run effectively.

**Kernel and user processes**

Kernel processes run in a privileged mode with full access to the system, handling essential tasks like resource management and security. User processes run in a restricted mode to prevent them from interfering with the kernel or other processes, enhancing security and system stability.

**CPUlator**

I used assembly code to output 1 and then create a pattern table to show the hex for each pattern. I then changed it to display 12345678.

After this I moved on to try it in C with the code provided.

## session 7
In this session I furthered my leaning from last lesson about the operating system.

Linux operating system

First I read about the history of Linux, firstly with how it started to to current day where its open source nature has made it the dominant operating system for cloud services and the internet.

Operating system structure

We looked at the key components of the operating system and wether they could be accessed or not.

The kernel is responsible for ensuring the operating system runs efficiently and securely without conflict between the hardware and software.

File systems and security

File permissions are crucial to the security model used by Linux systems.

## session 8 (consolidate)

TBD

