#include "shell.h"
#include <stdlib.h>
/**
 * _connects - program that returns true if shell is connected
 * @i: input structure to the address
 * Return: 1 otherwise 0
 */
int _connects(info_t *i)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * _delimeter - program that checks if char is a delimeter
 * @x: input delimeter string
 * @c: input character to be checked
 * Return: 1 else 0
 */
int _delimeter(char c, char *x)
{
while (*x)
if (*x++ == c)
return (1);
return (0);
}
/**
 * isalpha - program that checks for alphabetic char
 * @s: input string of char
 * Return: 1 otherwise 0
 */
int isalpha(int s)
{
if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
return (1);
return (0);
}
/**
 * atoi - program that converts string to an int
 * @c: input cnverted string
 * Return: 0 on Success
 */
int atoi(char *c)
{
int a, b = 1;
int s = 0, r;
unsigned int total = 0;
for (a = 0; c[a] != '\0' && s != 2; a++)
{
if (c[a] == '-')
b *= -1;
if (c[i] >= '0' && c[a] <= '9')
{
s = 1;
total *= 10;
total += (c[a] - '0');
}
else if (s == 1)
s = 2;
}
if (b == -1)
r = -total;
else
r = total;
return (r);
}
