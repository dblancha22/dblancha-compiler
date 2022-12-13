.global adder
.global multer
.text

.global main
main:
	pushq %rbp
	movq  %rsp, %rbp
	subq $24,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	movq $7,%rbx
	movq %rbx, -8(%rbp)
	movq $8,%rbx
	movq %rbx, -16(%rbp)
	movq -8(%rbp),%rbx
	movq -16(%rbp),%r10
	mov %rbx, %rdi
	mov %r10, %rsi
	pushq %r10
	pushq %r11
	call multer
	popq %r11
	popq %r10
	movq %rax, %rbx
	movq %rbx, -24(%rbp)
	movq -24(%rbp),%rbx
	pushq %r10
	pushq %r11
	mov %rbx, %rdi
	call print_integer
	popq %r11
	popq %r10
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq  %rbp, %rsp
	popq %rbp
	ret
.text

.global adder
adder:
	pushq %rbp
	movq  %rsp, %rbp
	pushq %rdi
	pushq %rsi
	subq $16,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	movq $0,%rbx
	movq %rbx, -32(%rbp)
	movq $0,%rbx
	mov %rbx, -24(%rbp)
.L1:
	movq -24(%rbp),%rbx
	movq -16(%rbp),%r10
	cmp %r10, %rbx
	jl .L3
	mov $0, %rbx
	jmp .L4
.L3:
	mov $1, %rbx
.L4:
	cmp $0, %rbx
	jz .L2
	movq -32(%rbp),%rbx
	movq -8(%rbp),%r10
	add %rbx, %r10
	mov %r10, -32(%rbp)
	leaq -24(%rbp), %rbx
	mov (%rbx), %r10
	mov %r10, %r11
	add $1, %r10
	mov %r10, (%rbx)
	jmp .L1
.L2:
	movq -32(%rbp),%rbx
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
.text

.global multer
multer:
	pushq %rbp
	movq  %rsp, %rbp
	pushq %rdi
	pushq %rsi
	subq $8,%rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	movq -8(%rbp),%rbx
	movq -16(%rbp),%r10
	mov %rbx, %rax
	imul %r10
	mov %rax, %r10
	movq %r10, -24(%rbp)
	movq -24(%rbp),%rbx
	movq -8(%rbp),%r10
	movq -16(%rbp),%r11
	mov %r10, %rdi
	mov %r11, %rsi
	pushq %r10
	pushq %r11
	call adder
	popq %r11
	popq %r10
	movq %rax, %r10
	cmp %r10, %rbx
	je .L7
	mov $0, %rbx
	jmp .L8
.L7:
	mov $1, %rbx
.L8:
	cmp $0, %rbx
	jz .L5
	movq -24(%rbp),%rbx
	movq %rbx,%rax
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
	jmp .L6
.L5:
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
.L6:
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq  %rbp, %rsp
	popq %rbp
	ret
