
/**
 *_islower - check if a letter is uppercase or not
 *
 *@c: the character to be checked
 *
 *Return: 1 if lowecase, 0 otherwise
 */

int _islower(int c)
{
	if ((c >= 97) && (c <= 122))
		return (1);
	else
		return (0);
}
