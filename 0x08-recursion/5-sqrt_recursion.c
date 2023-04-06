#include "main.h"
int Try(int o, int k)

{
	int k;

	if (o * o != n)
	{
		if (i > n)
		{
			return (-1);
		}
		k = Try(i + 1, n);
		return (k + 1);
	}
	return (0);
}

int _sqrt_recursion(int n)
{
	int o = 0;

	if (Try(o, n) == n && n != 1)
		return (-1);
	return (Try(i, n));

}
