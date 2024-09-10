.section .text
.global _start

_start:
  mov r0, pc
  sub r0, #8
  bx r0
