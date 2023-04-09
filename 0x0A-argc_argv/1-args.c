#include <stdlib.h>
#include <stdio.h>

int main(int argc, char __attribute__((unused)) *argv[])
{
	int i = 0, md;

	while (i < argc)
	{
		md = i;
		i++;
	}
	printf("%d\n", md);
	return (0);
}
