/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:04:00 by gtorvald          #+#    #+#             */
/*   Updated: 2019/09/23 14:04:01 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_abs(long long int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

static char	*str(char **num, long long int n)
{
	if (n % 10 == -8 && n / 10 == -922337203685477580)
		ft_strcpy(*num, "-9223372036854775808");
	else
		ft_strcpy(*num, "0");
	return (*num);
}

static int	get_size(long long int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_itoa(long long int n)
{
	char	*number;
	int		i;
	int		flag;
	int		size;

	size = get_size(n);
	if (!(number = malloc((size + 1) * sizeof(char))))
		return (NULL);
	number[size] = '\0';
	flag = 0;
	if ((n % 10 == -8 && n / 10 == -922337203685477580) || n == 0)
		return (number = str(&number, n));
	if (n < 0)
		flag = 1;
	i = size - 1;
	while (n != 0)
	{
		number[i--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (flag)
		number[i] = '-';
	return (number);
}
