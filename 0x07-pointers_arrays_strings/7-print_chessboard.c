#include "main.h"
/**
 * print_chessboard
 */
void print_chessboard(char (*a)[8])
{
	int i;
	int j;

	while (i < 64)
	{
		if (i % 8 == 0 && i != 0)
		{
			j = i;
			_putchar('\n');
		}

		_putchar(a[i / 8][i - j]);
		i++;
	}
	_putchar('\n');
}
