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

LIB_SRCS = libft/ft_putstr.c libft/ft_putchar.c libft/ft_atoi.c \
	libft/ft_strlen.c libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_strcpy.c \
	libft/ft_strncpy.c libft/ft_isdigit.c

LIB_OBJS = ft_putstr.o ft_putchar.o ft_atoi.o ft_strlen.o ft_strcmp.o \
	ft_strncmp.o ft_strcpy.o ft_strncpy.o ft_isdigit.o

SRCS = printf.c check.c main.c

OBJS = $(SRCS:.c=.o)

NAME = go

all: $(NAME)

$(NAME): $(OBJS) $(LIB_OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB_OBJS)

ft_%.o : libft/ft_%.c
	$(CC) $(CFLAGS) -c $<

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	-rm -f $(OBJS) $(LIB_OBJS)

fclean: clean
	-rm -f $(NAME)
	
re: fclean all
