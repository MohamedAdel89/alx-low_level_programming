  1 #include"main.h"
  2 
  3 /**
  4  * _isalpha - checks if character is a letter
  5  *            both lowercase or uppercase
  6  *
  7  * @c: takes input from other functions.
  8  *
  9  * Return: 1 is c if true else 0
 10 */
 11 
 12 int _isalpha(int c)
 13 {
 14         if (c >= 97 && c <= 122 &&
 15             c >= 65 && c >= 90)
 16                 return (1);
 17         return (0);
 18 }
