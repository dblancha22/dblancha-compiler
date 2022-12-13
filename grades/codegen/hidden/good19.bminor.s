
.data
c1: .quad 1
c3: .quad 100

.text
.global C
C: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi
PUSHQ %rsi

SUBQ $24, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $11, %r10
MOVQ %r10, -24(%rbp)
MOVQ $12, %r10
MOVQ %r10, -32(%rbp)
MOVQ $13, %r10
MOVQ %r10, -40(%rbp)
MOVQ -8(%rbp), %r10
MOVQ -16(%rbp), %r11
ADDQ %r10, %r11
MOVQ -24(%rbp), %r10
ADDQ %r11, %r10
MOVQ -32(%rbp), %r11
ADDQ %r10, %r11
MOVQ %r11, %rax
JMP .C_epilogue

.C_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $1, %r11
MOVQ $2, %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL C
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ %r10, %rax
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

