
.data
a1: .quad 0
a2: .quad 111
a3: .quad 0

.text
.global A
A: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ a3, %r10
CMP $1, %r10
JE .L0
JMP .L1
.L0:
MOVQ a1, %r11
MOVQ a2, %r12
MOVQ %r11, %rax
IMULQ %r12
MOVQ %rax, %r12
MOVQ %r12, %rax
JMP .A_epilogue
.L1:
MOVQ $3, %r10
MOVQ %r10, -8(%rbp)
MOVQ $0, %rax
MOVQ $0, %rax
MOVQ $0, %rax
MOVQ a3, %r10
CMP $0, %r10
SETZ %al
MOVQ %rax, %r10
CMP $0, %r10
SETZ %al
MOVQ %rax, %r10
CMP $0, %r10
SETZ %al
MOVQ %rax, %r10
CMP $1, %r10
JE .L2
JMP .L3
.L2:
MOVQ a1, %r11
MOVQ -8(%rbp), %r12
ADDQ %r11, %r12
MOVQ %r12, %rax
JMP .A_epilogue
.L3:
MOVQ $0, %r10
MOVQ %r10, %rax
JMP .A_epilogue

.A_epilogue:
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
CALL A
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

