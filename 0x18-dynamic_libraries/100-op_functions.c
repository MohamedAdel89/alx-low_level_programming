#include <stdio.h>
#include "100-calc.h"

/**
 *add - computes the sum of two numbers
 *@a: first number
 *@b: second number
 *Return: sum of two numbers
 */

int add(int a, int b)
{
	return (a + b);
}

/**
 *sub - computes the difference between two numbers
 *@a: first number (+a)
 *@b: second number (-b)
 *Return: difference of two numbers
 */

int sub(int a, int b)
{
	return (a - b);
}

/**
 *mul - computes the product of two numbers
 *@a: first number
 *@b: second number
 *Return: product of two numbers
 */

int mul(int a, int b)
{
	return (a * b);
}

/**
 *div - computes the division of two numbers
 *@a: first number (num)
 *@b: second number (den)
 *Return: division of two numbers
 */

int div(int a, int b)
{
	if (b == 0)
	{
		puts("Error");
		return (100);
	}
	return (a / b);
}

/**
 *mod - computes the remainder of the division of two numbers
 *@a: first number (num)
 *@b: second number (den)
 *Return: remainder of the division of two numbers
 */

int mod(int a, int b)
{
	if (b == 0)
	{
		puts("Error");
		return (100);
	}
	return (a % b);
}
