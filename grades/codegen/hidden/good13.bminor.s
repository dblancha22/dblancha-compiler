
.text
.global foo_epilogue
foo_epilogue: 
PUSHQ %rbp
MOVQ %rsp, %rbp


SUBQ $0, %rsp

PUSHQ %rbx
PUSHQ %r12
PUSHQ %r13
PUSHQ %r14
PUSHQ %r15

MOVQ $2, %r10
MOVQ %r10, %rax
JMP .foo_epilogue_epilogue

.foo_epilogue_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET


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

PUSHQ %r10
PUSHQ %r11
CALL foo
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $11, %r11
MOVQ %r10, %rax
IMULQ %r11
MOVQ %rax, %r11
MOVQ %r11, %rax
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

.global main_epilogue
main_epilogue: 
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
CALL foo_epilogue
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $3, %r11
ADDQ %r10, %r11
MOVQ %r11, %rax
JMP .main_epilogue_epilogue

.main_epilogue_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

.global foo
foo: 
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
CALL main_epilogue
POPQ %r11
POPQ %r10
MOVQ %rax, %r10
MOVQ $1, %r11
SUBQ %r11, %r10
MOVQ %r10, %rax
JMP .foo_epilogue

.foo_epilogue:
POPQ %r15
POPQ %r14
POPQ %r13
POPQ %r12
POPQ %rbx
MOVQ %rbp, %rsp

POPQ %rbp
RET

