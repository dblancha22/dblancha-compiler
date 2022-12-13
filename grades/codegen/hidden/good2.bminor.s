
.data
X: .quad 11, 30, 22, 0

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
LEA X, %r10
MOVQ -8(%rbp), %r11
MOVQ $8, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r10
MOVQ (%r10), %r10
MOVQ $0, %r10
CMPQ %r10, %r10
JNE .L2
MOVQ $0, %r10
JMP .L3
.L2:
MOVQ $1, %r10
.L3:
CMP $0, %r10
JE .L1
LEA X, %r11
MOVQ -8(%rbp), %r12
MOVQ $8, %r13
MOVQ %r12, %rax
IMULQ %r13
MOVQ %rax, %r13
ADDQ %r13, %r11
MOVQ (%r11), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $32, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_character
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
LEA X, %r11
MOVQ -8(%rbp), %r12
MOVQ $8, %r13
MOVQ %r12, %rax
IMULQ %r13
MOVQ %rax, %r13
ADDQ %r13, %r11
MOVQ (%r11), %r11
MOVQ $3, %r11
MOVQ %r11, %rax
CQO
IDIVQ %r11
MOVQ %rdx, %r11
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

