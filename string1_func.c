#include <stdlib.h>
#include "shell.h"
/**
 * _strcpy - program that copies a string
 * @dest: input destination
 * @src: input source
 * Return: dest to the pointer
 */
char *_strcpy(char *d, char *src)
{
int a = 0;
if (d == src || src == 0)
return (d);
while (src[a])
{
d[a] = src[a];
a++;
}
d[a] = 0;
return (d);
}
/**
 * _strdup - prigram that duplicates string
 * @str: input string to be duplicated
 * Return: pointer to the string
 */
char *_strdup(const char *str)
{
int len = 0;
char *r;
if (str == NULL)
return (NULL);
while (*str++)
len++;
r = malloc(sizeof(char) * (len + 1));
if (!r)
return (NULL);
for (len++; len--;)
r[len] = *--str;
return (r);
}
/**
 *_puts - program that prints input string
 *@str: input string to be printed
 * Return: void
 */
void _puts(char *str)
{
int a = 0;
if (!str)
return;
while (str[a] != '\0')
{
_putchar(str[a]);
a++;
}
}
/**
 * _putchar - program that writes the char c to stdout
 * @c: input char to be printed
 * Return: 1 on Success else -2 on Failure
 */
int _putchar(char c)
{
static int a;
static char b[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
{
write(1, b, a);
a = 0;
}
if (c != BUF_FLUSH)
b[a++] = c;
return (1);
}
