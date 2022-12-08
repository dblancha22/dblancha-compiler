
.text
.global fib
fib: 
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
MOVQ $1, %r11
CMPQ %r11, %r10
JL .L0
MOVQ $0, %r11
JMP .L1
.L0:
MOVQ $1, %r11
.L1:
CMP $1, %r11
JE .L2
MOVQ -8(%rbp), %r10
MOVQ $2, %r12
CMPQ %r12, %r10
JL .L3
MOVQ $0, %r12
JMP .L4
.L3:
MOVQ $1, %r12
.L4:
CMP $1, %r12
JE .L5
MOVQ -8(%rbp), %r13
MOVQ $1, %r14
SUBQ %r14, %r13
MOVQ %r13, %rdi
PUSHQ %r10
PUSHQ %r11
CALL fib
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r14
MOVQ $2, %r15
SUBQ %r15, %r14
MOVQ %r14, %rdi
PUSHQ %r10
PUSHQ %r11
CALL fib
POPQ %r11
POPQ %r10
MOVQ %rax, %r13
ADDQ %r10, %r13
MOVQ %r13, %rax
JMP .fib_epilogue
JMP .L6
.L5:
MOVQ $1, %r10
MOVQ %r10, %rax
JMP .fib_epilogue
.L6:
JMP .L7
.L2:
MOVQ $0, %r10
MOVQ %r10, %rax
JMP .fib_epilogue
.L7:

.fib_epilogue:
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

PUSHQ %rdi
PUSHQ %rsi

SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %r10
MOVQ %r10, -24(%rbp)

.data
.L8: .string "Table of Fibonnacci Numbers\n"

.text
LEA .L8, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $0, %r11
MOVQ %r11, -24(%rbp)
MOVQ %r11, %r10
.L9:
MOVQ -24(%rbp), %r10
MOVQ $30, %r11
CMPQ %r11, %r10
JL .L11
MOVQ $0, %r11
JMP .L12
.L11:
MOVQ $1, %r11
.L12:
CMP $0, %r11
JE .L10
MOVQ -24(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L13: .string "t"

.text
LEA .L13, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -24(%rbp), %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL fib
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L14: .string "\n"

.text
LEA .L14, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -24(%rbp), %r11
MOVQ $1, %r12
ADDQ %r11, %r12
MOVQ %r12, -24(%rbp)
MOVQ %r12, %r10
JMP .L9
.L10:
MOVQ $0, %r10
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

