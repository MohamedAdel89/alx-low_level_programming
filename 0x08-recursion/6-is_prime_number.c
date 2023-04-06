#include "main.h"
int Try(int x, int y)
{
	if (y < 2 || y % x == 0)
		return (0);
	else if (x > y / 2)
		return (1);
	else
		return (Try (x + 1, y));
}

int prime_number(int n)
{
	if (n == 2)
		return (1);
	return (Try(2, n));
}
