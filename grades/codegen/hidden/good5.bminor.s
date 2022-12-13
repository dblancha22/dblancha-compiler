
.data

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

MOVQ $100, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL B
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ $1, %r12
SUBQ %r12, %r11
MOVQ $10, %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL A
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
CMP $1, %r10
JE .L0
JMP .L1
.L0:
MOVQ $3, %r11
MOVQ %r11, -8(%rbp)
MOVQ $2, %r11
MOVQ $33, %r13
MOVQ %r13, %rdi
PUSHQ %r10
PUSHQ %r11
CALL B
POPQ %r11
POPQ %r10
MOVQ %rax, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
MOVQ -8(%rbp), %r11
ADDQ %r12, %r11
MOVQ %r11, %rax
JMP .main_epilogue
.L1:

.data
.L2: .string "hello"

.text
LEA .L2, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL C
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL B
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $3, %r11
MOVQ %r10, %rax
CQO
IDIVQ %r11
MOVQ %rdx, %r11
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

.global A
A: 
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

MOVQ -8(%rbp), %r10
MOVQ -16(%rbp), %r11
CMPQ %r11, %r10
JE .L3
MOVQ $0, %r11
JMP .L4
.L3:
MOVQ $1, %r11
.L4:
MOVQ %r11, %rax
JMP .A_epilogue

.A_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

.global B
B: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi

SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ -8(%rbp), %r10
MOVQ $33, %r11
CMPQ %r11, %r10
JE .L5
MOVQ $0, %r11
JMP .L6
.L5:
MOVQ $1, %r11
.L6:
CMP $1, %r11
JE .L7
MOVQ $11, %r10
MOVQ %r10, %rax
JMP .B_epilogue
JMP .L8
.L7:
MOVQ $10, %r10
MOVQ %r10, %rax
JMP .B_epilogue
.L8:

.B_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

.global C
C: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi

SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $33, %r10
MOVQ %r10, %rax
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

