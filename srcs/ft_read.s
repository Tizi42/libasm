;ssize_t ft_read(int fd, void *buf, size_t count);

			global	ft_read

			extern	__errno_location

			section	.text
			
ft_read:	mov		rax, 0
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

