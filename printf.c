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

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;

	g_count = 0;
	va_start(ap, format);
	while(*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(ap, char*));
		}
		format++;
	}
	va_end(ap);
	return (g_count);
}
