#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 *op_add - computes the sum of two numbers
 *@a: first number
 *@b: second number
 *Return: sum of two numbers
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 *op_sub - computes the difference between two numbers
 *@a: first number (+a)
 *@b: second number (-b)
 *Return: difference of two numbers
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 *op_mul - computes the product of two numbers
 *@a: first number
 *@b: second number
 *Return: product of two numbers
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 *op_div - computes the division of two numbers
 *@a: first number (num)
 *@b: second number (den)
 *Return: division of two numbers
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		puts("Error");
		exit(100);
	}
	return (a / b);
}

/**
 *op_mod - computes the remainder of the division of two numbers
 *@a: first number (num)
 *@b: second number (den)
 *Return: remainder of the division of two numbers
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		puts("Error");
		exit(100);
	}
	return (a % b);
}
