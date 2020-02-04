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

void	print_sign_of_number(t_argument arg, char *num, int flag)
{
	int		count;

	count = ft_strlen(num);
	if (arg.precision + (*num == '-') > count)
		count = arg.precision + (*num == '-');
	if (!flag)
	{
		if (*num == '-' && (check(arg.flags, '0') ||
			(int)ft_strlen(num) - 1 <= arg.precision))
			ftb_putchar('-');
		else if (check("di", arg.type) && *num != '-' && check(arg.flags, '+') &&
			((check(arg.flags, '0') && arg.width > count) || arg.width <= count))
			ftb_putchar('+');
		else if (check("di", arg.type) && *num != '-' && check(arg.flags, ' '))
			if ((int)ft_strlen(num) > arg.precision)
				ftb_putchar(' ');	
	}
	else
		if (check("di", arg.type) && *num != '-' && check(arg.flags, '+') &&
			(!check(arg.flags, '0') || arg.width < count) && arg.width > count)
			ftb_putchar('+');
}

void	print_flags_and_number(t_argument arg, char *num)
{
	print_sign_of_number(arg, num, 0);
	print_alternative_form(arg, num, 0);
	if (!check(arg.flags, '-'))
		print_indentantion(arg, num);
	print_alternative_form(arg, num, 1);
	print_sign_of_number(arg, num, 1);
	print_symbols('0', arg.precision - ft_strlen(num) + (*num == '-'));
	if (!ft_strcmp(num, "0") && arg.precision == 0 && arg.width > 0)
		ftb_putchar(' ');
	else if (ft_strcmp(num, "0") || arg.precision != 0)
		ftb_putstr(num + (*num == '-' && (check(arg.flags, '0') ||
		(int)ft_strlen(num) - 1 <= arg.precision)));
	if (check(arg.flags, '-'))
		print_indentantion(arg, num);
}

void	print_integer_number(t_argument argument, va_list ap)
{
	char		*num;
	t_argument	help_arg;

	if (argument.type == 'p')
	{
		help_arg = get_info_about_argument("#lx", ap);
		help_arg.width = argument.width;
		help_arg.precision = argument.precision;
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
