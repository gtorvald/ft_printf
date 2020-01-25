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

	system = 10;
	if (argument.type == 'o')
		system = 8;
	if (argument.type == 'x' || argument.type == 'X')
		system = 16;
	if (argument.size == 'L')
		return (ft_itoa_un(va_arg(ap, unsigned long long int), system));
	else if (argument.size == 'l')
		return (ft_itoa_un(va_arg(ap, unsigned long int), system));
	else if (argument.size == '0')
		return (ft_itoa_un(va_arg(ap, unsigned int), system));
	else if (argument.size == 'h')
		return (ft_itoa_un((unsigned short int)va_arg(ap, int), system));
	else
		return (ft_itoa_un((unsigned char)va_arg(ap, int), system));
}

void	print_integer_number(t_argument argument, va_list ap)
{
	char	*num;

	if (argument.type == 'd' || argument.type == 'i')
		num = get_string_of_number(argument, ap);
	else
		num = get_string_of_unsigned_number(argument, ap);
	ft_putstr(num);
	g_count += ft_strlen(num);
	free(num);
}
