
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

MOVQ $4, %r10
MOVQ $9, %r11
MOVQ $2, %r12
NEGQ %r12
MOVQ $5, %r13
NEGQ %r13
SUBQ %r13, %r12
MOVQ %r11, %rax
CQO
IDIVQ %r12
MOVQ %rdx, %r12
ADDQ %r10, %r12
MOVQ $2, %r10
MOVQ $1, %r11
ADDQ %r10, %r11
MOVQ $4, %r10
MOVQ %r11, %rax
IMULQ %r10
MOVQ %rax, %r10
MOVQ $1, %r11
SUBQ %r11, %r10
MOVQ $3, %r11
MOVQ %r10, %rax
CQO
IDIVQ %r11
MOVQ %rdx, %r11
MOVQ $7, %r10
MOVQ %r11, %rax
IMULQ %r10
MOVQ %rax, %r10
ADDQ %r12, %r10
MOVQ $2, %r12
MOVQ $3, %r13
MOVQ %r12, %rdi
MOVQ %r13, %rsi
PUSHQ %r10
PUSHQ %r11
CALL integer_power
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
SUBQ %r11, %r10
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

