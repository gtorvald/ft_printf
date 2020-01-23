/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:47:21 by gtorvald          #+#    #+#             */
/*   Updated: 2019/12/22 21:47:28 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			get_number_from_string(const char *format, va_list ap)
{
	if (*format == '*')
		return (va_arg(ap, int));
	return (ft_atoi(format));
}

t_argument	get_info_about_argument(const char *format, va_list ap)
{
	t_argument	argument;
	int			i;

	i = 0;
	while (check("+- #0", format[i]))
		i++;
	argument.flags = malloc(sizeof(char) * i);
	argument.flags[i - 1] = '\0';
	ft_strncpy(argument.flags, format, i);
	argument.width = get_number_from_string(format + i, ap);
	while (!check("%scpdiouxXfLhl", format[i]))
		if (format[i++] == '.')
			argument.precision = get_number_from_string(format + i, ap);
	if (!ft_strncmp(format + i, "hh", 2))
		argument.size = 'H';
	else if (!ft_strncmp(format + i, "ll", 2))
		argument.size = 'L';
	else if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
		argument.size = format[i];
	while (!check("%scpdiouxXf", format[i]))
		i++;
	argument.type = format[i];
	return (argument);
}

int			main_function(const char *format, va_list ap)
{
	t_argument	argument;
	int			count;

	argument = get_info_about_argument(format + 1, ap);
	printf("flags(%s)\n", argument.flags);
	printf("wigth(%d)\n", argument.width);
	printf("precision(%d)\n", argument.precision);
	printf("size(%c)\n", argument.size);
	printf("type(%c)\n", argument.type);
	count = 1;
	while (format[count] != argument.type)
		count++;
	return (count);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	ap;

	g_count = 0;
	va_start(ap, format);
	while(*format != '\0')
	{
		if (*format == '%')
			format += main_function(format, ap);
		else
		{
			ft_putchar(*format);
			g_count++;
		}
		format++;
	}
	va_end(ap);
	return (g_count);
}
