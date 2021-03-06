# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 15:29:29 by gtorvald          #+#    #+#              #
#    Updated: 2020/01/23 15:29:32 by gtorvald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -c -Wextra -Wall -Werror

LIB_OBJS = ft_putstr.o ft_putchar.o ft_atoi.o ft_strlen.o ft_strcmp.o \
	ft_strncmp.o ft_strcpy.o ft_strncpy.o ft_isdigit.o ft_itoa.o \
	ft_toupper.o ft_strcat.o\
	\
	ftb_itoa_unsigned.o ftb_putchar.o ftb_putstr.o ftb_nputstr.o 

SRCS = printf.c stuff.c char.c integer.c integer_help.c double.c double_help.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	ar rc $(NAME) $(LIB_OBJS) $(OBJS)
	ranlib $(NAME)

ft_%.o : libft/ft_%.c
	$(CC) $(CFLAGS) -c $<

ftb_%.o : libftbonus/ftb_%.c
	$(CC) $(CFLAGS) -c $<

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	-rm -f $(OBJS) $(LIB_OBJS)

fclean: clean
	-rm -f $(NAME)
	
re: fclean all
