#include <stdio.h>
#include "header.h"

int 	main(void)
{
	ft_printf("(%-10s)\n", "abcd");
	ft_printf("(%10s)\n", "abcd");
	ft_printf("(%10.10s)\n", "abcd");
	ft_printf("(%.10s)\n", "abcd");
	ft_printf("(%10c)\n", 'a');
	ft_printf("=== TEST ===\n");
	printf("(%-10s)\n", "abcd");
	printf("(%10s)\n", "abcd");
	printf("(%10.10s)\n", "abcd");
	printf("(%.10s)\n", "abcd");
	printf("(%10c)\n", 'a');
	return (0);
}
