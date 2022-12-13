
.text
.global D
D: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $64, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $5, %r10
MOVQ %r10, -8(%rbp)
MOVQ -8(%rbp), %r10
MOVQ $1, %r11
ADDQ %r10, %r11
MOVQ %r11, -16(%rbp)
MOVQ $9, %r10
MOVQ %r10, -24(%rbp)
MOVQ -24(%rbp), %r10
MOVQ -8(%rbp), %r11
ADDQ %r10, %r11
MOVQ $3, %r10
SUBQ %r10, %r11
MOVQ %r11, -32(%rbp)
MOVQ $1, %r10
NEGQ %r10
MOVQ %r10, -40(%rbp)
MOVQ -32(%rbp), %r11
MOVQ -24(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, -32(%rbp)
MOVQ %r12, %r10
MOVQ -32(%rbp), %r11
MOVQ -40(%rbp), %r12
SUBQ %r12, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L0: .string "\n"

.text
LEA .L0, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $16, %r10
MOVQ %r10, -48(%rbp)
MOVQ -16(%rbp), %r11
MOVQ -48(%rbp), %r12
SUBQ %r12, %r11
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
MOVQ $2, %r10
NEGQ %r10
MOVQ %r10, -56(%rbp)
MOVQ $1000, %r10
MOVQ %r10, -64(%rbp)
MOVQ -64(%rbp), %r11
MOVQ $10, %r12
ADDQ %r11, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L1: .string "\n"

.text
LEA .L1, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -56(%rbp), %r11
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
MOVQ -48(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $3, %r10
MOVQ %r10, %rax
JMP .D_epilogue

.D_epilogue:
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

PUSHQ %r10
PUSHQ %r11
CALL D
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

