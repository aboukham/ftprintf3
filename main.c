#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("hello %7.5u\n",-14);
	printf("hello %7.5u\n",-14);
	return (0);
}
