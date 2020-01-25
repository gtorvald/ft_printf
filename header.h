/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorvald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 21:47:57 by gtorvald          #+#    #+#             */
/*   Updated: 2019/12/22 21:47:58 by gtorvald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_argumet
{
	char		type;
	char		*flags;
	int			width;
	int			precision;
	char		size;
}				t_argument;

int				g_count;

int				check(char *str, char sym);
char			*ft_itoa_un(unsigned long long int n, int system);

void			print_char(t_argument argument, va_list ap);
void			print_integer_number(t_argument argument, va_list ap);

int				ft_printf(const char *restrict format, ...);

#endif
