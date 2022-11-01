# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/08 10:58:34 by tyuan             #+#    #+#              #
#    Updated: 2021/01/08 10:58:39 by tyuan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a

SFILES	= ft_write.s ft_read.s \
		  ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s

SRCS	= ${addprefix srcs/, ${SFILES}}

OBJS	= ${SRCS:.s=.o}

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

LEAK	= -fsanitize=address -g

TEST	= run_test

all:	${NAME}

${NAME}: ${OBJS}
	@ar rc $@ $^

%.o	: %.s
	@nasm -f elf64 $^

test: all
	@${CC} ${CFLAGS} ${LEAK} -no-pie -I includes/ -L. -lasm main.c ${NAME} -o ${TEST}
	@./${TEST}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${TEST}
	@${RM} write_in_me.txt

re: fclean all

.PHONY:	all test clean fclean re
