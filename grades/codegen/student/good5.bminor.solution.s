.data

.global x
x:
	.quad 2
	.quad 5
	.quad 8
	.quad 1
	.quad 4
	.quad 82
	.quad 31
	.quad 2
	.quad 20
	.quad 1029
.text

.global main
main:
	pushq %rbp
	movq  %rsp, %rbp
	subq $8,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	movq $0,%rbx
	mov %rbx, -8(%rbp)
.L1:
	movq -8(%rbp),%rbx
	movq $10,%r10
	cmp %r10, %rbx
	jl .L3
	mov $0, %rbx
	jmp .L4
.L3:
	mov $1, %rbx
.L4:
	cmp $0, %rbx
	jz .L2
	leaq x,%rbx
	movq -8(%rbp),%r10
	mov (%rbx,%r10,8), %r11
	movq $2,%rbx
	mov %r11, %rax
	cqo
	idiv %rbx
	mov %rdx, %rbx
	movq $0,%r10
	cmp %r10, %rbx
	je .L7
	mov $0, %rbx
	jmp .L8
.L7:
	mov $1, %rbx
.L8:
	cmp $0, %rbx
	jz .L5
.data
.S0:	.string "even"
.text
	leaq .S0,%rbx
	pushq %r10
	pushq %r11
	mov %rbx, %rdi
	call print_string
	popq %r11
	popq %r10
	jmp .L6
.L5:
	leaq x,%rbx
	movq -8(%rbp),%r10
	mov (%rbx,%r10,8), %r11
	movq $2,%rbx
	mov %r11, %rax
	cqo
	idiv %rbx
	mov %rdx, %rbx
	movq $0,%r10
	cmp %r10, %rbx
	jne .L11
	mov $0, %rbx
	jmp .L12
.L11:
	mov $1, %rbx
.L12:
	cmp $0, %rbx
	jz .L9
.data
.S1:	.string "odd"
.text
	leaq .S1,%rbx
	pushq %r10
	pushq %r11
	mov %rbx, %rdi
	call print_string
	popq %r11
	popq %r10
	jmp .L10
.L9:
.L10:
.L6:
	leaq -8(%rbp), %rbx
	mov (%rbx), %r10
	mov %r10, %r11
	add $1, %r10
	mov %r10, (%rbx)
	jmp .L1
.L2:
	movq $0,%rbx
	movq %rbx,%rax
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq  %rbp, %rsp
	popq %rbp
	ret
