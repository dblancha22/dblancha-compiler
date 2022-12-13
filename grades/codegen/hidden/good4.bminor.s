
.text
.global collatz
collatz: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi
PUSHQ %rsi

SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $10, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_character
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r10
MOVQ $1, %r11
CMPQ %r11, %r10
JE .L0
MOVQ $0, %r11
JMP .L1
.L0:
MOVQ $1, %r11
.L1:
CMP $1, %r11
JE .L2
JMP .L3
.L2:
MOVQ -16(%rbp), %r10
MOVQ %r10, %rax
JMP .collatz_epilogue
.L3:
MOVQ -8(%rbp), %r10
MOVQ $2, %r11
MOVQ %r10, %rax
CQO
IDIVQ %r11
MOVQ %rdx, %r11
MOVQ $0, %r10
CMPQ %r10, %r11
JE .L4
MOVQ $0, %r10
JMP .L5
.L4:
MOVQ $1, %r10
.L5:
CMP $1, %r10
JE .L6
MOVQ $3, %r12
MOVQ -8(%rbp), %r13
MOVQ %r12, %rax
IMULQ %r13
MOVQ %rax, %r13
MOVQ $1, %r12
ADDQ %r13, %r12
MOVQ -16(%rbp), %r13
MOVQ $1, %r14
ADDQ %r13, %r14
MOVQ %r12, %rdi
MOVQ %r14, %rsi
PUSHQ %r10
PUSHQ %r11
CALL collatz
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rax
JMP .collatz_epilogue
JMP .L7
.L6:
MOVQ -8(%rbp), %r12
MOVQ $2, %r13
MOVQ %r12, %rax
CQO
IDIVQ %r13
MOVQ %rdx, %r13
MOVQ -16(%rbp), %r12
MOVQ $1, %r14
ADDQ %r12, %r14
MOVQ %r13, %rdi
MOVQ %r14, %rsi
PUSHQ %r10
PUSHQ %r11
CALL collatz
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rax
JMP .collatz_epilogue
.L7:

.collatz_epilogue:
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

MOVQ $27, %r11
MOVQ $0, %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL collatz
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

