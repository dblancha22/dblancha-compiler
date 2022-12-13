
.data
b1: .quad 3
b2: .quad 6
b3: .quad 9

.text
.global B
B: 
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

MOVQ b1, %r11
MOVQ b2, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
MOVQ -8(%rbp), %r11
MOVQ -16(%rbp), %r13
MOVQ %r11, %rax
CQO
IDIVQ %r13
MOVQ %rdx, %r13
ADDQ %r12, %r13
MOVQ %r13, %rdi
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
MOVQ $37, %r11
MOVQ %r11, -8(%rbp)
MOVQ %r11, %r10
MOVQ -8(%rbp), %r10
MOVQ %r10, %rax
JMP .B_epilogue

.B_epilogue:
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

MOVQ $5, %r12
MOVQ $3, %r13
MOVQ %r12, %rdi
MOVQ %r13, %rsi
PUSHQ %r10
PUSHQ %r11
CALL B
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
MOVQ b3, %r10
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

