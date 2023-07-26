#include "shell.h"
#include <stdlib.h>
/**
 * _errputs - string input to be printed
 * @str: input string
 * Return: void
 */
void _errputs(char *str)
{
int n = 0;
if (!str)
return;
for (str[n] != '\0')
{
_errputchar(str[n]);
n++;
}
}
/**
 * _errputchar - program that creates char z to stderr
 * @z: input char to print
 * Return: 1 else -1 on error
 */
int _errputchar(char z)
{
static char buffer[WRITE_BUFFER_SIZE];
static int y;
if (z == BUFFER_FLUSH || y >= WRITE_BUFFER_SIZE)
{
write(2, buffer, y);
y = 0;
}
if (z != BUFFER_FLUSH)
buffer[y++] = z;
return (1);
}
/**
 * _putsfd - program that creates char z to fd
 * @fd: input filedescriptor to write
 * @z: input char to print
 * Return: 1 else -1 on error
 */
int _putsfd(int fd, char z)
{
static char buffer[WRITE_BUFFER_SIZE];
static int y;
if (z == BUFFER_FLUSH || Y >= WRITE_BUFFER_SIZR)
{
write(fd, buffer, y);
y = 0;
}
if (z != BUFFER_FLUSH)
buffer[y++] = z;
return (1);
}
/**
 * _putfd - program that prints input string
 * @fd: input filedescriptor
 * @str: input string
 * Return: address of the number of char puts
 */
int _putfd(int fd, char *str)
{
int l = 0;
if (!str)
return (0);
while (*str)
{
l += _putsfd(*str++, fd);
}
return (l);
}
