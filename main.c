#include <stdio.h>
#include "header.h"

int 	main(void)
{
	ft_printf("%+- #*.*ll%\n", 23, 12, "345");
	ft_printf("=== TEST ===\n");
	printf("%d\n", 345);
	return (0);
}
