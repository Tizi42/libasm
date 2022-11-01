;int strcmp(const char *s1, const char *s2);

            global  ft_strcmp

            section .text

ft_strcmp:  xor     rax, rax
            xor     rcx, rcx
loop:       mov     al, byte [rdi]
            mov     cl, byte [rsi]
            sub     rax, rcx       ; If use al, cl: 00000000 - 01100001 = 10011111
            cmp     al, 0
            jne     end
            cmp     byte [rdi], 0
            je      end
            cmp     byte [rsi], 0
            je      end
            inc     rdi
            inc     rsi
            jmp     loop

end:        cmp     rax, 0
            jl      less
            je      zero
            jg      greater

less:       mov     rax, -1
            ret
zero:       mov     rax, 0
            ret
greater:    mov     rax, 1
            ret

