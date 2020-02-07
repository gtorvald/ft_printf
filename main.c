#include <stdio.h>
#include "header.h"

int 	main(void)
{
	printf("|%d\n", ft_printf("%.2c", NULL));
	ft_printf("=== TEST ===\n");
	printf("|%d\n", printf("%.2c", NULL));
}
