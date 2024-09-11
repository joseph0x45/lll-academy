# The Fetch-Decode-Execute cycle

## Fetch
Every CPU has a $pc register standing for Program Counter. It contains a pointer to the next instruction to be executed.
At the end of this stage, the Control Unit has the instruction to execute.

## Decode
The Control Unit needs to instruct the rest of the CPU. At the end of this stage, every component (registers, main memory, ALU...) have their orders.

## Execute
The instruction takes place. At the end of this stage, the instruction has been executed and the $pc contains the pointer to the next instruction.
If the instruction wasn't a branching instruction, to get the next pointer will add the `word size` which is the size in bytes of each register 
(32 bit for ARM so **4** ) to the current value inside $pc to get the next instruction in line.
