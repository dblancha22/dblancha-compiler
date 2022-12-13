
.data
big_global: .quad .L0

.L0: .string "I AM THE BIGGEST\n"

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
.L1: .string "NO I AM BIGGER\n"

.text
LEA .L1, %r10
MOVQ %r10, -8(%rbp)

.data
.L2: .string "I AM TEMPORARY\n"

.text
LEA .L2, %r10
MOVQ %r10, -16(%rbp)
MOVQ big_global, %r11
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
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -16(%rbp), %r11
MOVQ %r11, %rdi
PUSHQ %r10
PUSHQ %r11
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ big_global, %r11
MOVQ %r11, -16(%rbp)
MOVQ %r11, %r10
MOVQ -8(%rbp), %r11
MOVQ %r11, big_global
MOVQ %r11, %r10
MOVQ -16(%rbp), %r11
MOVQ %r11, -8(%rbp)
MOVQ %r11, %r10
MOVQ big_global, %r11
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
CALL print_string
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ -16(%rbp), %r11
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

