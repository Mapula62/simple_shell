#include "shell"
#include <stdlib.h>
/**
 * _free - a program that frees pointer to the address
 * @t: pointer to the address
 * Return: 1 oelse 0
 */
int _free(void **t)
{
if (t && *t)
{
free(*t);
*t = NULL;
return (1);
}
return (0);
}
