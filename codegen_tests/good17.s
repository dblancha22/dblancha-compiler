
.data
global_s: .quad .L0

.L0: .string "equals\n"

.text
.global main
main: 
PUSHQ %rbp
MOVQ %rsp, %rbp

PUSHQ %rdi

SUBQ $8, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15


.data
.L1: .string "equals\n"

.text
LEA .L1, %r10
MOVQ %r10, -16(%rbp)

.data
.L2: .string "I have "

.text
LEA .L2, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -8(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_integer
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L3: .string " function arguments\n"

.text
LEA .L3, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L4: .string "also, global_s == local_s = "

.text
LEA .L4, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ global_s, %r12
MOVQ -16(%rbp), %r13
MOVQ %r12, %rdi
MOVQ %r13, %rsi
PUSHQ %r10
PUSHQ %r11
CALL string_compare
POPQ %r11
POPQ %r10
MOVQ %rax, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_boolean
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.data
.L5: .string " very cool\n"

.text
LEA .L5, %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10

.main_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

