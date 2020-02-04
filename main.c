#include <stdio.h>
#include "header.h"

int 	main(void)
{
	ft_printf("%.2s is a string\n", "");
	ft_printf("%-.2s is a string\n", "");
	ft_printf("(%.2s)\n", "a");
	ft_printf("=== TEST ===\n");
	printf("%.2s is a string\n", "");
	printf("%-.2s is a string\n", "");
	printf("(%.2s)\n", "a");
}
