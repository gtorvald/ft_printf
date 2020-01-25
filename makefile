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

#LIB_SRCS = libft/ft_putstr.c libft/ft_putchar.c libft/ft_atoi.c \
#	libft/ft_strlen.c libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_strcpy.c \
#	libft/ft_strncpy.c libft/ft_isdigit.c libft/ft_itoa.c \
#	\
#	libftbonus/ftb_itoa_unsigned.c

LIB_OBJS = ft_putstr.o ft_putchar.o ft_atoi.o ft_strlen.o ft_strcmp.o \
	ft_strncmp.o ft_strcpy.o ft_strncpy.o ft_isdigit.o ft_itoa.o \
	ft_toupper.o \
	\
	ftb_itoa_unsigned.o ftb_putchar.o ftb_putstr.o ftb_nputstr.o

SRCS = printf.c stuff.c char.c integer.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	#$(CC) -o $(NAME) $(OBJS) $(LIB_OBJS)
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
