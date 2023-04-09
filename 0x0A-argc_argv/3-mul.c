#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int md;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		md = (atoi(argv[1]) * atoi(argv[2]));
		printf("%d\n", md);
	}
	return (0);
}
