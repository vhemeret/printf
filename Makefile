# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 22:23:16 by vahemere          #+#    #+#              #
#    Updated: 2021/12/04 23:21:59 by vahemere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/ft_printf.c \
		src/ft_printf_utils.c \

OBJS = ${SRC:.c=.o}

NAME = libftprintf.a
CC = gcc -Wall -Wextra -Werror
INC = -I./include

all :	$(NAME)

.c.o :
	${CC} ${INC} -c $< -o ${<:.c=.o}

$(NAME) :	$(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean :	clean
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re