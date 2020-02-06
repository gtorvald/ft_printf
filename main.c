#include <stdio.h>
#include "header.h"

int 	main(void)
{
	printf("|%d\n", ft_printf("%+5.i", 0));
	printf("|%d\n", ft_printf("%5p", 0));
	ft_printf("=== TEST ===\n");
	printf("|%d\n", printf("%+5.i", 0));
	printf("|%d\n", printf("%5p", 0));
}
