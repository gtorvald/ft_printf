/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:37:24 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/23 17:37:33 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_string(t_argument argument, char *string)
{
	int		len;

	len = ft_strlen(string);
	if (argument.precision != -1 && len > argument.precision)
		len = argument.precision;
	if (!check(argument.flags, '-'))
		while (argument.width-- - len > 0)
			ftb_putchar(' ');
	if (argument.precision != -1)
		ftb_nputstr(string, argument.precision);
	else if (string != NULL)
		ftb_putstr(string);
	else
		ftb_putstr("(null)");
	while (argument.width-- - len > 0)
		ftb_putchar(' ');
}

void	print_char(t_argument argument, va_list ap)
{
	char	*string;

	if (argument.type != 's')
	{
		string = malloc(2 * sizeof(char));
		string[1] = '\0';
		if (argument.type == '%')
			string[0] = '%';
		else
			string[0] = (char)va_arg(ap, int);
		print_string(argument, string);
		free(string);
	}
	else
		print_string(argument, va_arg(ap, char*));
}
