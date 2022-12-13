
.data
s: .quad .L0

.L0: .string "wow"
s2: .quad .L1

.L1: .string "WOW"

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

MOVQ s, %r11
MOVQ s2, %r12
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
.L3: .string "cap"

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

.data
.L5: .string "no cap"

.text
LEA .L5, %r12
MOVQ %r12, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
.L4:

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

