
.data
x: .quad 1

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

MOVQ $0, %r11
MOVQ %r11, x
MOVQ %r11, %r10
.L0:
MOVQ x, %r10
MOVQ $10, %r11
CMPQ %r11, %r10
JL .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $0, %r11
JE .L1
MOVQ x, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L4: .string "\n"

.text
LEA .L4, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ x, %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, x
JMP .L0
.L1:
MOVQ $0, %r10
MOVQ %r10, -8(%rbp)
.L5:
MOVQ -8(%rbp), %r10
MOVQ $10, %r11
CMPQ %r11, %r10
JL .L7
MOVQ $0, %r11
JMP .L8
.L7:
MOVQ $1, %r11
.L8:
CMP $0, %r11
JE .L6
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L9: .string "\n"

.text
LEA .L9, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -8(%rbp)
JMP .L5
.L6:
MOVQ $0, %r11
MOVQ %r11, x
MOVQ %r11, %r10

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

