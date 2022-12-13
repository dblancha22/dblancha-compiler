
.data

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


.data
.L0: .string "hi"

.text
LEA .L0, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL strlen
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

.data
.L1: .string "there"

.text
LEA .L1, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL strlen
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
CMPQ %r11, %r10
JG .L2
MOVQ $0, %r11
JMP .L3
.L2:
MOVQ $1, %r11
.L3:
CMP $1, %r11
JE .L4
JMP .L5
.L4:

.data
.L6: .string "no\n"

.text
LEA .L6, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
.L5:

.data
.L7: .string "hi"

.text
LEA .L7, %r13
MOVQ %r13, %rdi
PUSHQ %r10
PUSHQ %r11
CALL strlen
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

.data
.L8: .string "there"

.text
LEA .L8, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL strlen
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
CMPQ %r11, %r10
JG .L9
MOVQ $0, %r11
JMP .L10
.L9:
MOVQ $1, %r11
.L10:
CMP $1, %r11
JE .L11
JMP .L12
.L11:

.data
.L13: .string "ok\n"

.text
LEA .L13, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
.L12:
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

MOVQ -8(%rbp), %r10
MOVQ $2, %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r11
MOVQ %r11, %rax
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

