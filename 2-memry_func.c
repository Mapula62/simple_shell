#include "shell.h"
#include <stdlib.h>
/**
 * _interac -function that returns interactive mode
 * @n: input struct address
 * Return: 1 else 0
 */
int _interac(info_t *n)
{
return (isatty(STDIN_FILENO) && n->readfd <= 2);
}
/**
 * _delimeter - program that checks if character is a delimeter
 * @d: input delimeter string
 * @n: number of character to be checked
 * Return: 1 else 0
 */
int _delimeter(char *d, char n)
{
while (*d)
if (*d++ == n)
return (1);
else
return (0);
}
/**
 * _isalpha - function that checks for alphabets
 * @n: input character
 * Return: 1 else 0;
 */
int _isalpha(int n)
{
if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
return (1);
return (0);
}
/**
 * _atoi - function that converts string to an integer
 * @size: size of the string to be  convertrd
 * Return: converted number of strings, else 0
 */
int _atoi(char *size)
{
unsigned int t = 0;
int n, l;
int s = 1, f = 0;
for (n = 0; size[n] != '\0' && f != 2; n++)
{
if (size[n] == '-')
s *= -1;
if (size[n] >= '0' && size[n] <= '9')
{
f = 1;
t *= 10;
t += (size[n] - '0');
}
if (f == 1)
f = 2;
}
if (s == -1)
l = -t;
else
l = t;
return (l);
}
