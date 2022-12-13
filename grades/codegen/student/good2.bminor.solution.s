.data

.global x
x:
	.quad 6
.text

.global main
main:
	pushq %rbp
	movq  %rsp, %rbp
	subq $16,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	movq $3,%rbx
	movq %rbx, -8(%rbp)
	movq x,%rbx
	leaq -8(%rbp), %r10
	mov (%r10), %r11
	mov %r11, %r12
	add $1, %r11
	mov %r11, (%r10)
	add %rbx, %r12
	movq %r12, -16(%rbp)
	movq -16(%rbp),%rbx
	movq $20,%r10
	sub %r10, %rbx
	movq -8(%rbp),%r10
	mov %rbx, %rax
	imul %r10
	mov %rax, %r10
	movq x,%rbx
	movq $4,%r11
	mov %rbx, %rax
	imul %r11
	mov %rax, %r11
	add %r10, %r11
	movq %r11,%rax
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
