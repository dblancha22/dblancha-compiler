.data

.global x
x:
	.quad 20
.text

.global main
main:
	pushq %rbp
	movq  %rsp, %rbp
	subq $0,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
.L1:
	movq x,%rbx
	movq $5,%r10
	neg %r10
	cmp %r10, %rbx
	jg .L5
	mov $0, %rbx
	jmp .L6
.L5:
	mov $1, %rbx
.L6:
	cmp $0, %rbx
	jz .L3
	movq x,%rbx
	pushq %r10
	pushq %r11
	mov %rbx, %rdi
	call print_integer
	popq %r11
	popq %r10
.data
.S0:	.string "\n"
.text
	leaq .S0,%rbx
	pushq %r10
	pushq %r11
	mov %rbx, %rdi
	call print_string
	popq %r11
	popq %r10
	leaq x, %rbx
	mov (%rbx), %r10
	mov %r10, %r11
	sub $1, %r10
	mov %r10, (%rbx)
	jmp .L4
.L3:
	movq $5,%rbx
	neg %rbx
	movq %rbx,%rax
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
.L4:
	jmp .L1
.L2:
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq  %rbp, %rsp
	popq %rbp
	ret
