/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:27:49 by gtorvald          #+#    #+#             */
/*   Updated: 2020/02/07 18:27:51 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

1) НАПИСАТЬ ВОЗВЕДЕНИЕ 2 В ОТРИЦАТЕЛЬНУЮ СТЕПЕНЬ
2) НАПИСАТЬ СЛОЖЕНИЕ
3) НАПСАТЬ УМНОЖЕНИЕ
4) НАПИСАТЬ НОРМАЛЬНОЕ ВОЗВЕДЕНИЕ 2 В ПОЛОЖИТЕЛЬНУЮ СТЕПЕНЬ

#include <stdio.h>
#include "header.h"

char	*umn_na_dva(char *num)
{
	char	*result;
	char	*res;
	int		i, j;
	int		um;
	int		count;

	um = 0;
	count = 0;
	i = 2 * ft_strlen(num);
	result = malloc(sizeof(char) * (i + 1));
	result[i--] = '\0';
	j = ft_strlen(num) - 1;
	while (j >= 0)
	{
		result[i--] = ((num[j] - '0') * 2 + um) % 10 + '0';
		um = ((num[j--] - '0') * 2 + um) / 10;
		count++;
	}
	if (um != 0)
	{
		result[i] = um + '0';
		i--;
		count++;
	}
	res = malloc(sizeof(char) * (count + 1));
	res[count] = '\0';
	ft_strcpy(res, result + i + 1);
	free(result);
	return (res);
}

int		main(void)
{
	char *num;
	char *res;
	int i, st;

	res = malloc(sizeof(char) * 2);
	res[1] = '\0';
	res[0] = '1';
	printf("%s\n", res);
	i = 1084 - 1023;
	st = i;
	while (i-- > 0)
	{
		num = res;
		res = NULL;
		res = umn_na_dva(num);
	}
	printf("2 ^ %d = %s\n", st, res);
	
	double	numm = 4599676419421066752.000000;
	int		*str = (int*)&numm;
	i = 1;
	st = (str[1] >> 20) & 0x7ff;

	ft_printf("%d %x\n0x", st, st);
	while (i >= 0)
	{
		ft_printf("%08x", *(str + i));
		i--;
	}
	printf("\n%f\n", numm);
}
