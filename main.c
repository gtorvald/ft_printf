#include <stdio.h>
#include "header.h"

int 	main(void)
{
	printf("%d\n", ft_printf("%.p, %.0p", 0, 0));
	ft_printf("=== TEST ===\n");
	printf("%d\n", printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l));
}
