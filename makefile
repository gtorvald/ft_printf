CC = gcc
CFLAGS = -c -Wextra -Wall -Werror -I.
SRCS =	printf.c \
		libft/ft_putchar.c \
		libft/ft_putstr.c

OBJECTS = 	printf.o \
		ft_putchar.o \
		ft_putstr.o

NAME = libftprintf.a
	
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(HEADERS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o go

clean:
	-rm -f $(OBJECTS)

fclean: clean
	-rm -f $(NAME)
	
re: fclean all
