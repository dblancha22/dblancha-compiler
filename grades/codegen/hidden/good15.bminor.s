
.data

.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $16, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15


.data
.L0: .string "sssss"

.text
LEA .L0, %r10
MOVQ %r10, -8(%rbp)
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL strdup
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ %r10, -16(%rbp)
MOVQ -8(%rbp), %r11
MOVQ -16(%rbp), %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL string_compare
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
CMP $1, %r10
JE .L1
MOVQ $11, %r11
MOVQ %r11, %rax
JMP .main_epilogue
JMP .L2
.L1:
MOVQ $22, %r11
MOVQ %r11, %rax
JMP .main_epilogue
.L2:

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

