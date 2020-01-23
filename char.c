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
	if (!check(argument.flags, '-'))
		while (argument.width-- - len > 0)
			ft_putchar(' ');
	ft_putstr(string);
	while (argument.width-- - len > 0)
		ft_putchar(' ');
	if (argument.width > len)
		g_count += argument.width;
	else
		g_count += len;
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
