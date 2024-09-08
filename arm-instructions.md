# Instruction Format
ARM instructions typically follow a specific format:
```sh
<opcode>{<cond>} <Rd>, <Rn>, <operand2>
```
- opcode: The operation to be performed (e.g., ADD, MOV, LDR, STR).
- cond: (Optional) Condition under which the instruction is executed (e.g., EQ for equal, NE for not equal).
- Rd: Destination register where the result is stored.
- Rn: First operand register.
- operand2: Second operand, which can be a register, an immediate value, or a shifted register value.

# Quick recap
- ADD Rd, Rn, Rm       ; Add two registers (Rd = Rn + Rm)
- ADD Rd, Rn, #imm     ; Add a constant to a register (Rd = Rn + imm)
- LDR Rt, [base, #off] ; Load from memory (Rt = *(base + off))
- STR Rt, [base, #off] ; Store to memory (*(base + off) = Rt)
