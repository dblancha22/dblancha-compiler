
.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $40, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $20, %r10
MOVQ %r10, -8(%rbp)
MOVQ -8(%rbp), %r10
MOVQ %r10, -16(%rbp)
MOVQ $10, %r10
MOVQ %r10, -24(%rbp)
MOVQ -16(%rbp), %r11
MOVQ -24(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, -16(%rbp)
MOVQ %r12, %r10
MOVQ -16(%rbp), %r11
MOVQ -8(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, -16(%rbp)
MOVQ %r12, %r10
MOVQ $2, %r10
MOVQ %r10, -32(%rbp)
MOVQ -16(%rbp), %r11
MOVQ -32(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, -16(%rbp)
MOVQ %r12, %r10
MOVQ -16(%rbp), %r11
MOVQ -8(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, -16(%rbp)
MOVQ %r12, %r10
MOVQ $3, %r10
MOVQ %r10, -40(%rbp)
MOVQ -16(%rbp), %r11
MOVQ -40(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, -16(%rbp)
MOVQ %r12, %r10
MOVQ -16(%rbp), %r10
MOVQ -8(%rbp), %r11
ADDQ %r10, %r11
MOVQ %r11, %rax
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

