.section .text
.global _start

_start:
    b _start   @ Branch to _start, creating an infinite loop
