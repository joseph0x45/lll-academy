.section .text

.global _start

_start:
	ldr r0, =#0x13377331
	movw r1, 0xface
	movt r1, 0xf00d
