/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:57:57 by tyuan             #+#    #+#             */
/*   Updated: 2021/01/08 10:58:05 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libasm.h"

int main()
{
    char    longs[] = "Based on your input, get a random alpha numeric string. The random string generator creates a series of numbers and letters that have no pattern. These can be helpful for creating security codes. With this utility you generate a 16 character output based on your input of numbers and upper and lower case letters.  Random strings can be unique. Used in computing, a random string generator can also be called a random character string generator. This is an important tool if you want to generate a unique set of strings. The utility generates a sequence that lacks a pattern and is random. Throughout time, randomness was generated through mechanical devices such as dice, coin flips, and playing cards. A mechanical method of achieving randomness can be more time and resource consuming especially when a large number of randomized strings are needed as they could be in statistical applications.  Computational random string generators replace the traditional mechanical devices.";
    char    *dst1 = malloc(sizeof(char) * 5);
    char    *dst2 = malloc(sizeof(char) * 5);
    char    *dst3 = malloc(sizeof(char) * 10);
    char    *dst4 = malloc(sizeof(char) * 10);
    char    *dst5 = malloc(sizeof(char) * 1000);
    char    *dst6 = malloc(sizeof(char) * 1000);
    char    *strdup_str;
    int     fd;
    char    my_str[500];

    printf(BLUE "==================================================================\n" RESET);
    printf(BLUE ">>>>>>>>>>>>>>>>>>>>>>>>>>> Test START <<<<<<<<<<<<<<<<<<<<<<<<<<<\n" RESET);
    printf(BLUE "==================================================================\n" RESET);

    printf(RED "\n==================== Testing ft_strlen ====================\n" RESET);

    printf(GREEN "\n[TEST 1] Empty string:\n" RESET);
    printf("ft_strlen: %zu\n", ft_strlen(""));
    printf("   strlen: %zu\n", strlen(""));

    printf(GREEN "\n[TEST 2] Very short string: 'ab'\n" RESET);
    printf("ft_strlen: %zu\n", ft_strlen("ab"));
    printf("   strlen: %zu\n", strlen("ab"));

    printf(GREEN "\n[TEST 3] A very long string\n" RESET);
    printf("ft_strlen: %zu\n", ft_strlen(longs));
    printf("   strlen: %zu\n", strlen(longs));

    printf(RED "\n==================== Testing ft_strcpy ====================\n" RESET);

    printf(GREEN "\n[TEST 1] Src is an empty string:\n" RESET);
    printf("ft_strcpy:%s|\n", ft_strcpy(dst1, ""));
    printf("   strcpy:%s|\n", strcpy(dst2, ""));

    printf(GREEN "\n[TEST 2] Src is a short string: 'Hello'\n" RESET);
    printf("ft_strcpy: %s|\n", ft_strcpy(dst3, "Hello"));
    printf("   strcpy: %s|\n", strcpy(dst4, "Hello"));

    printf(GREEN "\n[TEST 3] Src is a very long string:\n" RESET);
    printf("===>ft_strcpy: \n%s|\n", ft_strcpy(dst5, longs));
    printf("===>strcpy: \n%s|\n", strcpy(dst6, longs));

    free(dst1);
    free(dst2);
    free(dst3);
    free(dst4);
    free(dst5);
    free(dst6);

    printf(RED "\n==================== Testing ft_strcmp ====================\n" RESET);

    printf(GREEN "\n[TEST 1] Empty string - Empty string:\n" RESET);
    printf("ft_strcmp: %i\n", ft_strcmp("", ""));
    printf("   strcmp: %i\n", strcmp("", ""));

    printf(GREEN "\n[TEST 2] Empty string - 'abc':\n" RESET);
    printf("ft_strcmp: %i\n", ft_strcmp("", "abc"));
    printf("   strcmp: %i\n", strcmp("", "abc"));

    printf(GREEN "\n[TEST 3] '123' - Empty string:\n" RESET);
    printf("ft_strcmp: %i\n", ft_strcmp("123", ""));
    printf("   strcmp: %i\n", strcmp("123", ""));

    printf(GREEN "\n[TEST 4] 'Hello, how are you?' - 'I am fine, thank you.':\n" RESET);
    printf("ft_strcmp: %i\n", ft_strcmp("Hello, how are you?", "I am fine, thank you."));
    printf("   strcmp: %i\n", strcmp("Hello, how are you?", "I am fine, thank you."));

    printf(GREEN "\n[TEST 5] 'Wow' - 'Meow':\n" RESET);
    printf("ft_strcmp: %i\n", ft_strcmp("Wow", "Meow"));
    printf("   strcmp: %i\n", strcmp("Wow", "Meow"));

    printf(GREEN "\n[TEST 6] '123' - '123456789':\n" RESET);
    printf("ft_strcmp: %i\n", ft_strcmp("123", "123456789"));
    printf("   strcmp: %i\n", strcmp("123", "123456789"));

    printf(RED "\n==================== Testing ft_write ====================\n" RESET);

    printf(GREEN "\n[TEST 1] Write a long string to stdout:\n" RESET);
    printf("\n");
    printf("\n===> ft_write: ret = %li\n\n", ft_write(1, longs, ft_strlen(longs)));
    printf("\n===> write: ret = %li\n", write(1, longs, strlen(longs)));

    printf(GREEN "\n[TEST 2] Write to a non exist fd 42:\n" RESET);
    printf("ft_write: ret = %li, errno = %i, msg = %s\n", ft_write(42, "Coucou", 6) , errno, strerror(errno));
    printf("   write: ret = %li, errno = %i, msg = %s\n", write(42, "Coucou", 6), errno, strerror(errno));

    printf(GREEN "\n[TEST 3] Write 'Coucou' to an open file: write_in_me.txt\n" RESET);
    fd = open("write_in_me.txt", O_RDWR | O_CREAT);
    printf("ft_write: fd = %i, ret = %li\n", fd, ft_write(fd, "Coucou", 6));
    printf("   write: fd = %i, ret = %li\n", fd, write(fd, "Coucou", 6));
    close(fd);

    printf(GREEN "\n[TEST 4] Write with str buf NULL to stdout:\n" RESET);
    printf("ft_write: ret = %li, errno = %i, msg = %s\n", ft_write(1, NULL, 6) , errno, strerror(errno));
    printf("   write: ret = %li, errno = %i, msg = %s\n", write(1, NULL, 6), errno, strerror(errno));

    printf(GREEN "\n[TEST 5] Write empty string to stdout:\n" RESET);
    printf("ft_write: ret = %li\n", ft_write(1, "", 0));
    printf("   write: ret = %li\n", write(1, "", 0));

    printf(GREEN "\n[TEST 6] Write to a non exist fd -1:\n" RESET);
    printf("ft_write: ret = %li, errno = %i, msg = %s\n", ft_write(-1, "test", 6) , errno, strerror(errno));
    printf("   write: ret = %li, errno = %i, msg = %s\n", write(-1, "test", 6), errno, strerror(errno));

    printf(RED "\n==================== Testing ft_read ====================\n" RESET);

    bzero(my_str, 500);

    printf(GREEN "\n[TEST 1] Read from stdin to my_str(max 500 characters):\n" RESET);
    printf("\n");
    printf("ft_read: ret = %li\n", ft_read(0, my_str, 500));

    fd = open("files/read_me.txt", O_RDONLY);
    printf(GREEN "\n[TEST 2] Read from read_me.txt to my_str:\n         (cat files/read_me.txt)\n" RESET);
    printf("ft_read: ret = %li, my_str: %s\n", ft_read(fd, my_str, 500), my_str);
    close(fd);
    
    printf(GREEN "\n[TEST 3] Read from a non exist fd 42:\n" RESET);
    printf("ft_read: ret = %li, errno = %i, msg = %s\n", ft_read(42, my_str, 500), errno, strerror(errno));

    printf(GREEN "\n[TEST 4] Read from read_me.txt to NULL:\n" RESET);
    fd = open("files/read_me.txt", O_RDONLY);
    printf("ft_read: ret = %li, errno = %i, msg = %s\n", ft_read(fd, NULL, 500), errno, strerror(errno));
    close(fd);

    printf(RED "\n==================== Testing ft_strdup ====================\n" RESET);

    printf(GREEN "\n[TEST 1] Empty string:\n" RESET);
    printf("ft_strdup:%s|\n", strdup_str = ft_strdup(""));
    free(strdup_str);
    printf("   strdup:%s|\n", strdup_str = strdup(""));
    free(strdup_str);

    printf(GREEN "\n[TEST 2] Looong str:\n" RESET);
    printf("===>ft_strdup:\n%s|\n", strdup_str = ft_strdup("Singin' in the Rain is a 1952 American musical romantic comedy film directed and choreographed by Gene Kelly and Stanley Donen, starring Kelly, Donald O'Connor, and Debbie Reynolds and featuring Jean Hagen, Millard Mitchell and Cyd Charisse. It offers a lighthearted depiction of Hollywood in the late 1920s, with the three stars portraying performers caught up in the transition from silent films to talkies."));
    free(strdup_str);
    printf("===>strdup:\n%s|\n", strdup_str = strdup("Singin' in the Rain is a 1952 American musical romantic comedy film directed and choreographed by Gene Kelly and Stanley Donen, starring Kelly, Donald O'Connor, and Debbie Reynolds and featuring Jean Hagen, Millard Mitchell and Cyd Charisse. It offers a lighthearted depiction of Hollywood in the late 1920s, with the three stars portraying performers caught up in the transition from silent films to talkies."));
    free(strdup_str);
    
    printf(GREEN "\n[TEST 3] Normal string:\n" RESET);
    printf("ft_strdup:%s|\n", strdup_str = ft_strdup("Coucou"));
    free(strdup_str);
    printf("   strdup:%s|\n", strdup_str = strdup("Coucou"));
    free(strdup_str);

    printf(BLUE "\n==================================================================\n" RESET);
    printf(BLUE ">>>>>>>>>>>>>>>>>>>>>>>>>>>>> Test END <<<<<<<<<<<<<<<<<<<<<<<<<<<\n" RESET);
    printf(BLUE "==================================================================\n" RESET);
    return 0;
}

