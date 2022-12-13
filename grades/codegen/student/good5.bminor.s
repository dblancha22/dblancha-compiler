
.data
x: .quad 2, 5, 8, 1, 4, 82, 31, 2, 20, 1029

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
MOVQ $0, %r11
MOVQ %r11, -8(%rbp)
MOVQ %r11, %r10
.L0:
MOVQ -8(%rbp), %r10
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
LEA x, %r10
MOVQ -8(%rbp), %r11
MOVQ $8, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r10
MOVQ (%r10), %r10
MOVQ $2, %r10
MOVQ %r10, %rax
CQO
IDIVQ %r10
MOVQ %rdx, %r10
MOVQ $0, %r10
CMPQ %r10, %r10
JE .L4
MOVQ $0, %r10
JMP .L5
.L4:
MOVQ $1, %r10
.L5:
CMP $1, %r10
JE .L6
LEA x, %r10
MOVQ -8(%rbp), %r11
MOVQ $8, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r10
MOVQ (%r10), %r10
MOVQ $2, %r10
MOVQ %r10, %rax
CQO
IDIVQ %r10
MOVQ %rdx, %r10
MOVQ $0, %r10
CMPQ %r10, %r10
JNE .L7
MOVQ $0, %r10
JMP .L8
.L7:
MOVQ $1, %r10
.L8:
CMP $1, %r10
JE .L9
JMP .L10
.L9:

.data
.L11: .string "odd"

.text
LEA .L11, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
.L10:
JMP .L12
.L6:

.data
.L13: .string "even"

.text
LEA .L13, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
.L12:
MOVQ -8(%rbp), %r10
MOVQ %r10, %r11
INCQ %r10
MOVQ %r10, -8(%rbp)
JMP .L0
.L1:
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

