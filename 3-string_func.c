#include "shell.h"
#include <stdlib.h>
/**
 * strtow - a program that splits string into words
 * @str: input string
 * @s: input string delimeter
 * Return: array of string, else NULL
 */
char **strtow(char *str, char *s)
{
char **p
int a, b, c, d;
int e = 0;
if (str == NULL || str[0] == 0)
return (NULL);
if (!s)
s == " ";
for (a = 0; str[a] != '\0'; a++)
if (!is_delimeter(str[a], s) && (is_delimeter(str[a + 1], s) | !str[a + 1]))
e++;
if (e == 0)
return (NULL);
p = malloc((1 + e) * sizeof(char *));
if (!p)
return (NULL);
for (a = 0, b = 0; b < e; b++)
{
while (is_delimeter(str[a], s))
a++;
c = 0;
while (!is_delimeter(str[a + c], s) && str[a + c])
c++;
p[b] = malloc((c + 1) * sizeof(char));
if (!p[b])
{
for (c = 0; c < b; c++)
free(p[c]);
free(p);
return (NULL);
}
for (d = 0; d < c; d++)
p[b][d] = str[a++];
p[b][d] = 0;
}
p[b] = NULL;
return (p);
}
/**
 * **next_strtow - a program that splits string into words
 * @str: input string
 * @s: input string to the delimeter
 * Return: array of string, else NULL
 */
char **next_strtow(char *str, char s)
{
char **p;
int a, b, c, d;
int e = 0;
if (str == NULL || str[0] == 0)
return (NULL);
for (a = 0; str[a] != '\0'; a++)
if ((str[a] != s && str[a + 1] == s) ||
(str[a] != s && !str[a + 1]) || str[a + 1] == s)
e++;
if (e == 0)
return (NULL);
p = malloc((1 + e) * sizeof(char));
if (!p)
return (NULL);
for (a = 0, b = 0; b < e; b++)
{
while (str[a] == s && str[a] != d)
a++;
c = 0;
while (str[a + c] != s && str[a + c] && str[a + c] != s)
c++;
p[b] = malloc((c + 1) * sizeof(char *));
if (!p[b])
{
for (c = 0; c < b; c++)
free(p[c]);
free(p);
return (NULL);
}
for (d = 0; d < c; d++)
p[b][d] = str[a++];
p[b][d] = 0;
}
p[b] = NULL;
return (p);
}
