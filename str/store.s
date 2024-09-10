.section .text
.global _start

_start:
  ldr r0, =mydata
  ldr r1, =#32
  str r1, [r0]


.section .data
mydata:
  .byte 0x0
