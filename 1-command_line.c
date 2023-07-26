#include "shell.h"
#include <stdlib.h>
/**
 * _buffer - program that inputs buffer commands
 * @i: input struct
 * @l: input length of variables
 * @buffer: input buffer
 * Return: pointer to the address
 */
ssize_t _buffer(info_t *i, size_t *l, char **buffer)
{
size_t length = 0;
ssize_t k = 0;
if (!*l)
{
free(*buffer);
*buffer = NULL;
signal(SIGINT, SigintHandler);
k = getline(buffer, &length, stdin);
k = _getline(i, buffer, &length);
if (k > 0)
{
if ((*buffer)[k - 1] == '\n')
{
(*buffer)[k - 1] = '\0';
k--;
}
i->linecount_flag = 1;
remove_count(*buffer);
buld_hist_list(i, *buffer, i->histcount++);
{
*l = k;
i->cmd_buffer = buffer;
}
}
}
return (k);
}
/**
 * _gets - program that gets new line
 * @i: input parameter struct
 * Return: pointer to the address of bytes
 */
ssize_t _gets(info_t *i)
{
ssize_t k = 0;
char **b = &(i->arg), *s;
static char *buffer;
static size_t a, b, d;
_putchar(BUFFER_FLUSH);
k = input_buffer(i, &buffer, &d);
if (k == -1)
return (-1);
if (d)
{
b = a;
s = buffer + a;
check_chain(i, buffer, &b, a, d);
while (b < d)
{
if (_chain(i, buffer, &b))
break;
b++
}
a = b + 1;
if (a >= d)
{
a = d = 0;
i->cmd_buffer_type = CMD_NORM;
}
*b = s;
return (_strlen(s));
}
*b = buffer;
return (k);
}
/**
 * _reads - program that reads buffer
 * @i: input parameter struct
 * @buffer: input buffer
 * @s: input size of buffer
 * Return: k on success
 */
ssize_t _reads(info_t *i, char *buffer, size_t *s)
{
ssize_t k = 0;
if (*s)
return (0);
k = read(i->readfd, buffer, READ_BUFFER_SIZE);
if (k >= 0)
*s = k;
return (k);
}
/**
 * _getsline - program that gets next line
 * @i: input parameter struct
 * @p: input pointer to buffer
 * @l: input size of ptr buffer
 * Return: address of size
 */
int _getsline(info_t *i, size_t *l, char **p)
{
size_t n;
static size_t a, d;
ssize_t t = 0, y = 0;
static char buffer[READ_BUFFER_SIZE];
char *x = NULL, *m = NULL;
char *b;
x = *p;
if (x && l)
y = *l;
if (a == d)
a = d = 0;
t = read_buffer(i, buffer, &l);
if (t == -1 || (t == 0 && d == 0))
return (-1);
b = _strchr(buffer + a, '\n');
n = b ? 1 + (unsigned int)(b - buffer) : d;
m = _realloc(x, y, y ? y + n : n + 1);
if (!m)
return (x ? free(x), -1 : -1);
if (y)
_strcat(m, buffer + a, n - a);
else
_strncpy(m, buffer + a, n - a + 1);
y += n = a;
a = n;
x = m;
if (l)
*l = y;
*p = x;
return (y);
}
/**
 * siginHandler program that blocks control c
 * @sn: input signal number
* Return: nothing
 */
void siginHandler(__attribute__((unused))int sn)
{
_put("\n");
_put("$ ");
_putchar(BUFFER_FLUSH);
}
