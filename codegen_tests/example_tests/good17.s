
.data
str: .quad .L0

.L0: .string "hello"
str2: .quad .L1

.L1: .string " world"

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

MOVQ str, %r10
MOVQ %r10, -8(%rbp)
MOVQ str, %r11
MOVQ -8(%rbp), %r12
MOVQ %r11, %rdi
MOVQ %r12, %rsi
PUSHQ %r10
PUSHQ %r11
CALL string_compare
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
CMP $1, %r10
JE .L2

.data
.L3: .string "shouldn't be printed"

.text
LEA .L3, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
JMP .L4
.L2:
MOVQ str, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
.L4:
MOVQ str, %r10
MOVQ str2, %r11
CMPQ %r11, %r10
JNE .L5
MOVQ $0, %r11
JMP .L6
.L5:
MOVQ $1, %r11
.L6:
CMP $1, %r11
JE .L7

.data
.L8: .string "shouldn't be printed"

.text
LEA .L8, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
JMP .L9
.L7:
MOVQ str2, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
.L9:

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

