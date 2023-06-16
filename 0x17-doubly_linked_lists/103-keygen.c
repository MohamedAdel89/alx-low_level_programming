#include <stdio.h>
#include <stdlib.h>
unsigned int _strlen(char *str);

/**
 *get_sum - get sum of all elements of a string
 *@str: string
 *Return: sum
 */

int get_sum(char *str)
{
	unsigned int i, sum = 0;

	for (i = 0; i < _strlen(str); i++)
		sum += (unsigned int) str[i];
	return (sum);
}

/**
 *get_mul - get multiplication of all elemnts of a string
 *@str: string
 *Return: mul
 */

int get_mul(char *str)
{
	unsigned int i, sum = 1;

	for (i = 0; i < _strlen(str); i++)
		sum *= (unsigned int) str[i];
	return (sum);
}

/**
 *get_greatest - get greatest char in a string
 *@str: string
 *Return: char
 */

int get_greatest(char *str)
{
	unsigned int i, buf = 0;

	for (i = 0; i < _strlen(str); i++)
		if ((unsigned int) str[i] > buf)
			buf = (unsigned int) str[i];
	return (buf);
}

/**
 *_strlen - calculates the length of a string
 *@str: string
 *Return: result
 */

unsigned int _strlen(char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 *main - Entry point
 *@argc: No. arguments
 *@argv: arguments
 *Return: 1
 */

int main(int argc, char *argv[])
{
	unsigned int i = 0, j = 0, buf = 0;
	char *str;
	/*create table*/
	char part1[] = "kuoIKdhPr1aQ3FeZqxf6Wjm4+ULYcJGOtvzX5s";
	char part2[] = "yVMnpgbiT2B9E0SNl78wDRHC-As4E{galf";
	char *letters = malloc(_strlen(part1) + _strlen(part2) + 1);
	/*create password*/
	char pass[7];

	(void) argc;
	while (part1[i] != '\0' || part2[j - i] != '\0')
	{
		if (part1[i] != '\0')
		{
			letters[i] = part1[i];
			i++;
		}
		else
			letters[j] = part2[j - i];
		j++;
	}
	letters[j + i] = '\0';
	srand((get_greatest(argv[1]) ^ 0xe));
	pass[0] = letters[0x3f - ((_strlen(argv[1]) ^ 0x3b) & 0x3f)];
	pass[1] = letters[0x3f - ((get_sum(argv[1]) ^ 0x4f) & 0x3f)];
	pass[2] = letters[0x3f - ((get_mul(argv[1]) ^ 0x55) & 0x3f)];
	pass[3] = letters[0x3f - (rand() & 0x3f)];
	buf = 0;
	str = argv[1];
	for (i = 0; i < _strlen(str); i++)
		buf += (unsigned int) str[i] * (unsigned int) str[i];
	pass[4] = letters[0x3f - ((buf ^ 0xef) & 0x3f)];
	buf = 0;
	for (i = 0; i < (unsigned int) str[0]; i++)
		buf = rand();
	pass[5] = letters[0x3f - ((buf ^ 0xe5) & 0x3f)];
	pass[6] = '\0';
	printf("%s", pass);
	return (1);
}
