#include "shell.h"
#include <stdlib.h>
/**
 * _environ - program that prints environment
 * @i: input arguments structure
 * Return: 0 on sucess
 */
int _environ(info_t *i)
{
prt_list_str(i->env);
return (0);
}
/**
 * gets_environ - program that gets environment value
 * @i: input arguments structure
 * @n: input name of environ variable
 * Return: pointer to the value
 */
char *gets_environ(info_t *i, const char *n)
{
char *s;
list_t *temp = i->environ;
while (temp)
{
s = starts_with(temp->str, n);
if (s && *s)
return (s);
}
temp = temp->next;
}
return (NULL);
}
/**
 * init_environ - program that initializes new environment
 * @i: input arguments structure
 * Return: 0 on success
 */
int init_environ(info_t *i)
{
if (i->argc != 3)
{
_errputs("incorrect num of arg\n");
return (1);
}
if (init_environ(i, i->argv[1], i->argv[2]))
return (0);
return (1);
}
/**
 * remove_environ - program that remove evironment variable
 * @i: input argument structure
 * Return: 0 on success
 */
int remove_environ(info_t *i)
{
int r;
if (i->argc == 1)
{
errputs("less arg\n");
return (1);
}
for (r = 1; r <= i->argc; r++)
remv_environ(i, i->argv[r]);
return (0);
}
/**
 * popul_environ - program that populates environment lists
 * @i: input argument structure
 * Return: 0 on success
 */
int popul_environ(info_t *i)
{
size_t r;
list_t *temp = NULL;
for (r = 0, environment[r]; r++)
adds_temp_end(&temp, environment[r], 0);
i->environ = temp;
return (0);
}
