#include <stdlib.h>
#include "shell.h"
/**
 * _strlen - program that returns string length
 * @str: input string length
 * Return: length of a string
 */
int _strlen(char *str)
{
int d = 0;
if (!str)
return (0);
while (*str++)
d++;
return (d);
}
/**
 * _strcmp - program that performs lexicogarphic
 * @x: input first strang
 * @y: input second strang
 * Return: negative if x else positive if y
 */
int _strcmp(char *x, char *y)
{
while (*x && *y)
{
if (*x != *y)
return (*x - *y)
x++;
y++;
}
if (*x == *y)
return (0);
else
return (*x < *y ? -1 : 1);
}
/**
 * starts_with - program that checks haystack
 * @h: input string to be search
 * @n: input substring to be find
 * Return: character of haystack else NULL
 */
char *starts_with(const char *h, const char *n)
{
while (*n)
if (*n++ != *h++)
return (NULL);
return ((char *)h);
}
/**
 * _strcat - program that concatenates two strings
 * @dest: input buffer destination
 * @src: input source buffer
 * Return: buffer destination
 */
char *_strcat(char *dest, char *src)
{
char *r = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);

