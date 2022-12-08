
.data

.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $24, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $7, %r10
MOVQ %r10, -8(%rbp)
MOVQ $8, %r10
MOVQ %r10, -16(%rbp)
MOVQ -8(%rbp), %r11
MOVQ -16(%rbp), %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL multer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ %r10, -24(%rbp)
MOVQ -24(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

.global adder
adder: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi
PUSHQ %rsi

SUBQ $16, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %r10
MOVQ %r10, -24(%rbp)
MOVQ $0, %r10
MOVQ %r10, -32(%rbp)
MOVQ $0, %r11
MOVQ %r11, -24(%rbp)
MOVQ %r11, %r10
.L0:
MOVQ -24(%rbp), %r10
MOVQ -16(%rbp), %r11
CMPQ %r11, %r10
JL .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $0, %r11
JE .L1
MOVQ -32(%rbp), %r11
MOVQ -8(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, -32(%rbp)
MOVQ %r12, %r10
MOVQ -24(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -24(%rbp)
JMP .L0
.L1:
MOVQ -32(%rbp), %r10
MOVQ %r10, %rax
JMP .adder_epilogue

.adder_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

.global multer
multer: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi
PUSHQ %rsi

SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ -8(%rbp), %r10
MOVQ -16(%rbp), %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r11
MOVQ %r11, -24(%rbp)
MOVQ -24(%rbp), %r10
MOVQ -8(%rbp), %r12
MOVQ -16(%rbp), %r13
MOVQ %r12, %rdi
MOVQ %r13, %rsi
PUSHQ %r10
PUSHQ %r11
CALL adder
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
CMPQ %r11, %r10
JE .L4
MOVQ $0, %r11
JMP .L5
.L4:
MOVQ $1, %r11
.L5:
CMP $1, %r11
JE .L6
MOVQ $0, %r10
MOVQ %r10, %rax
JMP .multer_epilogue
JMP .L7
.L6:
MOVQ -24(%rbp), %r10
MOVQ %r10, %rax
JMP .multer_epilogue
.L7:

.multer_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

