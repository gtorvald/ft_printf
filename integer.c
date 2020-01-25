/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:56:58 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/25 16:57:00 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_string_of_number(t_argument argument, va_list ap)
{
	if (argument.size == 'L')
		return (ft_itoa(va_arg(ap, long long int)));
	else if (argument.size == 'l')
		return (ft_itoa(va_arg(ap, long int)));
	else if (argument.size == '0')
		return (ft_itoa(va_arg(ap, int)));
	else if (argument.size == 'h')
		return (ft_itoa((short int)va_arg(ap, int)));
	else
		return (ft_itoa((signed char)va_arg(ap, int)));
}

char	*get_string_of_unsigned_number(t_argument argument, va_list ap)
{
	int		system;
	char	*num;

	system = 10;
	if (argument.type == 'o')
		system = 8;
	if (argument.type == 'x' || argument.type == 'X')
		system = 16;
	if (argument.size == 'L')
		num = ft_itoa_un(va_arg(ap, unsigned long long int), system);
	else if (argument.size == 'l')
		num = ft_itoa_un(va_arg(ap, unsigned long int), system);
	else if (argument.size == '0')
		num = ft_itoa_un(va_arg(ap, unsigned int), system);
	else if (argument.size == 'h')
		num = ft_itoa_un((unsigned short int)va_arg(ap, int), system);
	else
		num = ft_itoa_un((unsigned char)va_arg(ap, int), system);
	system = 0;
	if (argument.type == 'X')
		while (num[system++] != '\0')
			num[system - 1] = ft_toupper(num[system - 1]);
	return (num);
}

void	print_flags_and_number(t_argument arg, char *num)
{
	if (*num == '-' && check(arg.flags, '0'))
		ftb_putchar('-');
	if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#') &&
		(check(arg.flags, '-') || check(arg.flags, '0')))
	{
		ftb_putchar('0');
		ftb_putchar(arg.type);
	}
	if (arg.type == 'o' && check(arg.flags, '#') && (check(arg.flags, '-') ||
		check(arg.flags, '0')))
		ftb_putchar('0');
	if (!check(arg.flags, '-'))
		print_symbols(arg, arg.width - ft_strlen(num));
	if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#') &&
		(!check(arg.flags, '-') && !check(arg.flags, '0')))
	{
		ftb_putchar('0');
		ftb_putchar(arg.type);
	}
	if (arg.type == 'o' && check(arg.flags, '#') && (!check(arg.flags, '-')
		&& !check(arg.flags, '0')))
		ftb_putchar('0');
	ftb_putstr(num + (*num == '-' && check(arg.flags, '0')));
	if (check(arg.flags, '-'))
		print_symbols(arg, arg.width - ft_strlen(num));
}

void	print_integer_number(t_argument argument, va_list ap)
{
	char		*num;
	t_argument	help_arg;

	if (argument.type == 'p')
	{
		help_arg = get_info_about_argument("#lx", ap);
		print_integer_number(help_arg, ap);
		free(help_arg.flags);
		return ;
	}
	if (argument.type == 'd' || argument.type == 'i')
		num = get_string_of_number(argument, ap);
	else
		num = get_string_of_unsigned_number(argument, ap);
	print_flags_and_number(argument, num);
	free(num);
}
