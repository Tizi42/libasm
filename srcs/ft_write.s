;ssize_t ft_write(int fd, const void *buf, size_t count);

			global	ft_write

			extern	__errno_location

			section	.text
			
ft_write:	mov		rax, 1
			syscall
			cmp		rax, 0
			jl		error
			ret

error:		neg		rax
			push	rax
			call	__errno_location
			pop		r11
			mov		[rax], r11D
			mov		rax, -1
			ret

