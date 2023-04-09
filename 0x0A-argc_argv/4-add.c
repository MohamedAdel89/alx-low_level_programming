#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isNum(char num[])
{
	int md, l = strlen(num);

	for (md = 0; md < l; i++)
	{
		if (!isdigit(num[i]))
			return (1);
	}
	return (0);
}


int main(int argc, char *argv[])
{
	int md, sum;

	if (argc == 1)
	{
		printf("0\n");
	}
	else
	{
		sum = 0;
		for (md = 1; md < argc; md++)
		{
			if (isNum(argv[md]) == 0)
			{
				sum += atoi(argv[md]);
			}
			else
			{
				printf("Error\n");
				return (1);
			}
		}
		printf("%d\n", sum);
	}
	return (0);
}
