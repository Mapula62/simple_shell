#include "shell.h"
#include <stdlib.h>
/**
 * _eputs - program that prints input string
 * @str: input string
 * Return: void
 */
void _eputs(char *str)
{
int t = 0;
if (!str)
return;
while (str[t] != '\0')
{
_eputchar(str[t]);
t++;
}
}
/**
 * _eputchar - program that prints char s to stderr
 * @s: input char to be printed
 * Return: 1 on Success else -1 on error
 */
int _eputchar(char s)
{
static char bufffer[WRITE_BUF_SIZE];
static int b;
if (s == BUF_FLUSH || b >= WRITE_BUF_SIZE)
{
writes(2, buffer, b);
b = 0;
}
if (s != BUF_FLUSH)
buffer[b++] = s;
return (1);
}
/**
* _putfd -  program that prints char c to the given fd
* @s: input char to be printed
* @fd: input filedescriptor
* Return: 1 on Success else -1 error
*/
int _putfd(char s, int fd)
{
static char buffer[WRITE_BUF_SIZE];
static int d;
if (s == BUF_FLUSH || d >= WRITE_BUF_SIZE)
{
writes(fd, buffer, d);
d = 0;
}
if (s != BUF_FLUSH)
buffer[d++] = s;
return (1);
}
/**
 * _putsfd - program that prints string
 * @fd: input filedescriptor
 * @str: input string to be printed
 * Return: num of chars
*/
int _putsfd(int fd, char *str)
{
int a = 0;
if (!str)
return (0);
while (*str)
{
a += _putfd(*str++, fd);
}
return (a);
}
