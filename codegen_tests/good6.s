
.data
x: .quad 20

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

.L0:
MOVQ $1, %r10
CMP $0, %r10
JE .L1
MOVQ x, %r10
MOVQ $5, %r11
NEGQ %r11
CMPQ %r11, %r10
JG .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $1, %r11
JE .L4
MOVQ $5, %r10
NEGQ %r10
MOVQ %r10, %rax
JMP .main_epilogue
JMP .L5
.L4:
MOVQ x, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L6: .string "\n"

.text
LEA .L6, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ x, %r10
MOVQ %r10, %r12
DECQ %r10
MOVQ %r10, x
.L5:
JMP .L0
.L1:

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

