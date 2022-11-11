#include <stdio.h>

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		printf("ret = 1\n");
		return (1);
	}
	printf("ret = -1\n");
	return (-1);
}
