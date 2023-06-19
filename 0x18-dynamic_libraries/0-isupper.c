/**
 *_isupper - checks for a uppercase character.
 *@c: the character to be tested.
 *Return: 1 if uppercase, 0 otherwise.
 */

int _isupper(int c)
{
	if ((c >= 65) && (c <= 90))
		return (1);
	else
		return (0);
}
