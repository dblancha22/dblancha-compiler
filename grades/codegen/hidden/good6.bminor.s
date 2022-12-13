
.text
.global f
f: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi

SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $0, %rax
MOVQ -8(%rbp), %r10
CMP $0, %r10
SETZ %al
MOVQ %rax, %r10
MOVQ %r10, %rax
JMP .f_epilogue

.f_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET


.data
x: .quad 4

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

MOVQ $10, %r10
MOVQ %r10, -8(%rbp)
MOVQ x, %r15
MOVQ -8(%rbp), %r1-1
CMPQ %r1-1, %r15
JLE .L0
MOVQ $0, %r1-1
JMP .L1
.L0:
MOVQ $1, %r1-1
.L1:
MOVQ %r1-1, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r14
MOVQ %r14, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r13
MOVQ %r13, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL f
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
CMP $1, %r10
JE .L2
MOVQ x, %r11
MOVQ -8(%rbp), %r12
MOVQ x, %r13
MOVQ -8(%rbp), %r14
MOVQ %r13, %rax
IMULQ %r14
MOVQ %rax, %r14
SUBQ %r14, %r12
CMPQ %r12, %r11
JL .L3
MOVQ $0, %r12
JMP .L4
.L3:
MOVQ $1, %r12
.L4:
CMP $1, %r12
JE .L5
MOVQ $2, %r11
MOVQ %r11, %rax
JMP .main_epilogue
JMP .L6
.L5:
MOVQ $4, %r11
MOVQ %r11, %rax
JMP .main_epilogue
.L6:
JMP .L7
.L2:
MOVQ $1, %r11
MOVQ %r11, %rax
JMP .main_epilogue
.L7:

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

