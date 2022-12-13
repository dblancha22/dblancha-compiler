
.data
x: .quad 6

.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $16, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $3, %r10
MOVQ %r10, -8(%rbp)
MOVQ x, %r10
MOVQ -8(%rbp), %r11
MOVQ %r11, %r12
INCQ %r11
MOVQ %r11, -8(%rbp)
ADDQ %r10, %r12
MOVQ %r12, -16(%rbp)
MOVQ -16(%rbp), %r10
MOVQ $20, %r11
SUBQ %r11, %r10
MOVQ -8(%rbp), %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r11
MOVQ x, %r10
MOVQ $4, %r12
MOVQ %r10, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r11, %r12
MOVQ %r12, %rax
JMP .main_epilogue

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

