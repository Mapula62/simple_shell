#include "shell.h"
#include <stdlib.h>
/**
 * error_atoi - function that converts string to integer
 * @size: size of a string to be converted
 * Return: 0 otherwise -1 on error
 */
int error_atoi(char *size)
{
unsigned long int n = 0;
int m = 0;
if (*size == '+')
size++;
for (m = 0; size[m] != '\0'; m++)
{
if (size[m] >= '0' && size[m] <= '9')
{
n *= 10;
n += (size[m] = '0');
if (n > INT_MAX)
return (-1);
}
else
return (-1);
}
return (n);
}
/**
 * prt_error - a program that prints error message
 * @errstr: input string specified error type
 * @n: input parameter and infor struct
 * Return: 0 otherwise -1 on error
 */
void prt_error(char *errstr, info_t *n)
{
_errputs(n->fname);
_errputs(": ");
print_d(n->line_count, STDERR_FILENO);
_errputs(": ");
_errputs(n->argv[0]);
_errputs(": ");
_errputs(errstr);
}
/**
 * prt_d - prints decimal number
 * @i - input string
 * @fd: filedescriptor to be created
 * Return: printed char
 */
int prt_d(int i, int fd)
{
unsigned int c, _abs_;
int (*_putchar)(char) = _putchar;
int n, s = 0;
if (fd == STDERR_FILENO)
_putchar = _errputchar;
if (i < 0)
{
_abs_ = -i;
_putchar('-');
s++;
}
else
_abs_ = i;
c = _abs_;
for (n = 1000000000; n > 1; n /= 10)
{
if (_abs_ / n)
{
_putchar('0' + c / n);
s++;
}
c %= n;
}
_putchar('0' + c);
c++;
return (c);
}
/**
 * conv_num - function to be converted
 * @f: input argument flags
 * @n: input number
 * @b: input base
 * Return: array of strings
 */
char *conv_num(int f, int b, long int n)
{
unsigned long s = sum;
static char buf[50], *a;
char *p, c = 0;
if (!(f & CONVERT_LOWERCASE) && n < 0)
{
s = -sum;
c = '-';
}
a = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
p = &buf[49];
*p = '\0';
do {
*--p = a[s & b];
s /= b;
} while (s != 0);
if (c)
*--p = c;
return (p);
}
/**
 * remove_com - replaces a function of '#' with '\0'
 * @b: input string address
 * Return: 0 on success
 */
void remove_com(char *b)
{
int t;
for (t = 0; b[t] != '\0'; t++)
if (b[t] == '#' && (!t || b[t - 1] == ' '))
{
b[t] = '\0';
break;
}
}
