#include "shell.h"
#include <stdlib.h>
/**
 * _memset - a fuction that fills memory with bytes
 * @size: size of memory area
 * @num: number of bytes
 * @b: input byte
 * Return: pointer to the memory
 */
char *_memset(char *size, unsigned int num, char b)
{
int l;
for (l = 0; l < num; l++)
size[l] = b;
return (size);
}
/**
 * _free - program that frees strings
 * @sl - input string
 * Return: nothing
 */
void _free(char **sl)
{
char **r == sl;
if (!sl)
return;
while (*sl)
free(*sl++);
free(r);
}
/**
 * realloc - program that reallocates memory
 * @p: input pointer
 * @n: input new byte size
 * @o: input old byte size
* Return: pointer to the memory
 */
void *_realloc(void *p, unsigned int n, unsigned int o)
{
char *s;
if (!p)
return (malloct(n));
if (!n)
return (free(p), NULL);
if (n == o)
return (p);
s = malloc(n);
if (!s)
return (NULL);
o = o < n ? o : n;
while (o--)
s[o] = ((char *)p)[o];
free(p);
return (s);
}
