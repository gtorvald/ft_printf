#include "header.h"

char	*get_fractional_part(int precision, double num, char **number)
{
	char	*result;
	int		i;

	i = ft_strlen(*number) + 1;
	result = malloc(i + 1 + precision);
	ft_strcpy(result, *number);
	free(*number);
	ft_strcat(result, ".");
	while (precision-- > 0)
	{
		num *= 10;
		result[i++] = (long long int)num % 10 + '0';
	}
	return (result);
}

void	print_double(t_argument arg, va_list ap)
{
	double	num;
	char	*number;

	if (arg.precision == -1)
		arg.precision = 6;
	num = va_arg(ap, double);
	number = ft_itoa((long long int)num);
	if (arg.precision != 0)
		number = get_fractional_part(arg.precision, num, &number);
	print_flags_and_number(arg, number); //  функция не совсем подходит
}
