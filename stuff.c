/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 16:58:36 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/23 16:58:38 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "header.h"

int		check(char *str, char sym)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		if (str[i++] == sym)
		{
			if (sym != '0')
				return (1);
			else if (i - 2 < 0 || (str[i - 2] < '0' || str[i - 2] > '9'))
				return (1);
		}
	return (0);
}

void	print_symbols(char symbol, int count)
{
	while(count-- > 0)
		ftb_putchar(symbol);
}

void	print_indentantion(t_argument arg, char *num)
{
	int		count;

	count = ft_strlen(num);
	if (arg.precision + (*num == '-') > count)
		count = arg.precision + (*num == '-');
	if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#'))
		count += 2;
	if (arg.type == 'o' && check(arg.flags, '#'))
		count++;
	if (*num != '-' && check(arg.flags, '+'))
		count++;
	if (check(arg.flags, '0') && !check(arg.flags, '-') && arg.precision == -1)
		print_symbols('0', arg.width - count);
	else
		print_symbols(' ', arg.width - count);
}

void	print_alternative_form(t_argument arg, char *num, int flag)
{
	if (!flag)
	{
		if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#') &&
		(check(arg.flags, '-') || check(arg.flags, '0')) && ft_strcmp(num, "0"))
		{
			ftb_putchar('0');
			ftb_putchar(arg.type);
		}
		if (arg.type == 'o' && check(arg.flags, '#') && (check(arg.flags, '-') ||
			check(arg.flags, '0')))
			ftb_putchar('0');
	}
	else
	{
		if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#') &&
		(!check(arg.flags, '-') && !check(arg.flags, '0')) && ft_strcmp(num, "0"))
		{
			ftb_putchar('0');
			ftb_putchar(arg.type);
		}
		if (arg.type == 'o' && check(arg.flags, '#') && (!check(arg.flags, '-')
			&& !check(arg.flags, '0')))
			ftb_putchar('0');
	}
}
