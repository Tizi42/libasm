;char    *strdup(const char *s);

            global  ft_strdup

            section .text

            extern  malloc
            extern  ft_strlen
            extern  ft_strcpy

ft_strdup:  call    ft_strlen
            add     rax, 1
            push    rdi
            mov     rdi, rax
            call    malloc
            pop     rsi
            mov     rdi, rax
            call    ft_strcpy
            ret
