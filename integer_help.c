#include "header.h"

void	print_indentantion(t_argument arg, char *num)
{
	int		count;

	count = ft_strlen(num);
	if (check("di", arg.type) && *num != '-' && check(arg.flags, ' '))
		if ((int)ft_strlen(num) > arg.precision)
			arg.width--;
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
		if (arg.type == 'o' && check(arg.flags, '#') && (check(arg.flags, '-')
			|| check(arg.flags, '0')) && ((ft_strcmp(num, "0"))
			|| (!ft_strcmp(num, "0") && arg.precision == 0)) &&
			((int)ft_strlen(num) > arg.precision))
			ftb_putchar('0');
	}
	else
	{
		if ((arg.type == 'x' || arg.type == 'X') && check(arg.flags, '#') &&
		(!check(arg.flags, '-') && !check(arg.flags, '0')) &&
		ft_strcmp(num, "0"))
		{
			ftb_putchar('0');
			ftb_putchar(arg.type);
		}
		if (arg.type == 'o' && check(arg.flags, '#') && !check(arg.flags, '-')
			&& !check(arg.flags, '0') && ((ft_strcmp(num, "0"))
			|| (!ft_strcmp(num, "0") && arg.precision == 0)) &&
			((int)ft_strlen(num) > arg.precision))
			ftb_putchar('0');
	}
}

void	print_sign_of_number_frst(t_argument arg, char *num)
{
	int		count;

	count = ft_strlen(num);
	if (arg.precision + (*num == '-') > count)
		count = arg.precision + (*num == '-');
	if (*num == '-' && (check(arg.flags, '0') ||
		(((int)ft_strlen(num) - 1 <= arg.precision) &&
		arg.width <= arg.precision)))
		ftb_putchar('-');
	else if (check("di", arg.type) && *num != '-' && check(arg.flags, '+') &&
		((check(arg.flags, '0') && arg.width > count) || arg.width <= count))
		ftb_putchar('+');
	else if (check("di", arg.type) && *num != '-' && check(arg.flags, ' '))
		if ((int)ft_strlen(num) > arg.precision)
			ftb_putchar(' ');
}

void	print_sign_of_number_scnd(t_argument arg, char *num)
{
	int		count;

	count = ft_strlen(num);
	if (arg.precision + (*num == '-') > count)
		count = arg.precision + (*num == '-');
	if (*num == '-' && !check(arg.flags, '0') &&
		(int)ft_strlen(num) - 1 <= arg.precision &&
		arg.width > arg.precision)
		ftb_putchar('-');
	if (check("di", arg.type) && *num != '-' && check(arg.flags, '+') &&
		(!check(arg.flags, '0') || arg.width < count) && arg.width > count)
		ftb_putchar('+');
}
