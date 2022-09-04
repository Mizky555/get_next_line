#include <stdio.h>

int	increment(int number)
{
	static int	sum = 0;

	sum += number;

	printf("Current sum is %d\n", sum);
	return (sum);
}

int	main(void)
{
	increment(1);
	increment(2);
	increment(3);

	return (0);
}
