/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftb_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 20:40:45 by gtorvald          #+#    #+#             */
/*   Updated: 2020/01/25 20:40:47 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../header.h"

void	ftb_putstr(char *str)
{
	while (*str != '\0')
	{
		ftb_putchar(*str);
		str++;
	}
}
