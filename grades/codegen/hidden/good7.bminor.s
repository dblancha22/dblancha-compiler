
.text
.global f
f: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi

SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %r10
MOVQ %r10, -16(%rbp)
MOVQ $0, %r11
MOVQ %r11, -16(%rbp)
MOVQ %r11, %r10
.L0:
MOVQ -8(%rbp), %r10
MOVQ $0, %r11
CMPQ %r11, %r10
JG .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $0, %r11
JE .L1
MOVQ -16(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -16(%rbp), %r11
MOVQ $1, %r12
ADDQ %r11, %r12
MOVQ %r12, -16(%rbp)
MOVQ %r12, %r10
MOVQ -8(%rbp), %r10
MOVQ %r10, %r11
DECQ %r10
MOVQ %r10, -8(%rbp)
JMP .L0
.L1:

.f_epilogue:
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


SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $6, %r10
MOVQ %r10, -8(%rbp)
.L4:
MOVQ $1, %r10
CMP $0, %r10
JE .L5
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
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
MOVQ $0, %r11
CMPQ %r11, %r10
JE .L6
MOVQ $0, %r11
JMP .L7
.L6:
MOVQ $1, %r11
.L7:
CMP $1, %r11
JE .L8
JMP .L9
.L8:
MOVQ $0, %r10
MOVQ %r10, %rax
JMP .main_epilogue
.L9:
MOVQ -8(%rbp), %r10
MOVQ %r10, %r11
DECQ %r10
MOVQ %r10, -8(%rbp)
JMP .L4
.L5:
MOVQ $1, %r10
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

