#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 *main - entry point
 *@argc: number of arguments passed
 *@argv: array of strings
 *Return: 0 if succesful
 */

int main(int argc, char *argv[])
{
	int result;

	if (argc != 4)
	{
		puts("Error");
		exit(98);
	}

	result = (*get_op_func(argv[2]))(atoi(argv[1]), atoi(argv[3]));
	printf("%i\n", result);
	return (0);

}
