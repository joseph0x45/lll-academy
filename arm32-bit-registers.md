# ARM 32 bit registers
We have 2 types of registers:
- General Purpose registers (you can do whatever you want with them, mostly)
- Special Purpose registers

## General Purpose
You can do whatever you want with them, mostly. They are usually from r0 to r10

## Special Purpose
You are not supposed to touch them unless you know what you are doing.
### r11: Frame pointer register
Contains a pointer to the botton of the stack frame. The stack is memory where functions store data, whenever we are running a function, it creates
a new frame on the stack. The frame pointer points to the botton of the stack frame.
### r12: Intra Procedure Call register
Basically a place when you can leave data to send between functions. It is kind of like a GP but it's specific use is to store data that will be passed between functions
### r13: Stack pointer register
It points to the top of the stack frame
### r14: Link register
Contains the pointer to the memory location that contains the insruction to go back to when we return from a function.
### r15: Program counter
Contains the pointer to the next instruction
### CPSR: Current Program State Register
Flag register, contains flags that tell you about the state of the CPU. For example it could contain the carry bit of an addition that overflowed.


## Little recap

| Register | Description                    |
|----------|--------------------------------|
| R0-R12   | General-purpose registers      |
| R13 (SP) | Stack Pointer                  |
| R14 (LR) | Link Register                  |
| R15 (PC) | Program Counter                |
| CPSR     | Current Program Status Register|
