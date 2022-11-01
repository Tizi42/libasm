;char    *strcpy(char *dest, const char *src);

            global  ft_strcpy

            section .text

            extern  ft_strlen
            
ft_strcpy:  push    rdi
            mov     rdi, rsi
            call    ft_strlen
            pop     rdi
            mov     rcx, rax
            mov     rax, rdi
            CLD
            REP     MOVSB
            MOVSB
            ret

