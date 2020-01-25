#include <stdio.h>
#include "header.h"

int 	main(void)
{
	ft_printf("test: %llx\n", -123456789LL);
	ft_printf("test: %lx\n", -123456789L);
	ft_printf("test: %x\n", -123456789);
	ft_printf("test: %hx\n", (short int) -123456789);
	ft_printf("test: %hhx\n", (signed char) -123456789);
	ft_printf("=== TEST ===\n");
	printf("test: %llx\n", -123456789LL);
	printf("test: %lx\n", -123456789L);
	printf("test: %x\n", -123456789);
	printf("test: %hx\n", (short int) -123456789);
	printf("test: %hhx\n", (signed char) -123456789);
	return (0);
}

// %p = %#lx