
.data
a: .quad0, 0, 0, 0
.text
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

MOVQ $60, %r11
LEA a, %r12
MOVQ $2, %r13
MOVQ $8, %r14
MOVQ %r13, %rax
IMULQ %r14
MOVQ %rax, %r14
ADDQ %r14, %r12
MOVQ %r11, (%r12)
MOVQ %r11, %r10
LEA a, %r10
MOVQ $2, %r11
MOVQ $8, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r10
MOVQ (%r10), %r10
LEA a, %r10
MOVQ $2, %r11
MOVQ $8, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r10
MOVQ (%r10), %r10
MOVQ $20, %r10
MOVQ %r10, %rax
CQO
IDIVQ %r10
MOVQ %rdx, %r10
MOVQ $3, %r10
MOVQ %r10, %rax
IMULQ %r10
MOVQ %rax, %r10
ADDQ %r10, %r10
LEA a, %r10
MOVQ $1, %r11
MOVQ $8, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
ADDQ %r12, %r10
MOVQ (%r10), %r10
SUBQ %r10, %r10
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

