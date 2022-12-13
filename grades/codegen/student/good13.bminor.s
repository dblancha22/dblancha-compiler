
.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %r10
MOVQ %r10, -8(%rbp)
.L0:
MOVQ $1, %r10
CMP $0, %r10
JE .L1
MOVQ -8(%rbp), %r10
MOVQ $23, %r11
CMPQ %r11, %r10
JG .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $1, %r11
JE .L4
JMP .L5
.L4:
MOVQ -8(%rbp), %r10
MOVQ %r10, %rax
JMP .main_epilogue
.L5:
MOVQ -8(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -8(%rbp)
JMP .L0
.L1:

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

