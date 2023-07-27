#include <stdlib.h>
#include "shell.h"

/**
 * _env - program that prints current environ
 * @info: input struct containing arguments
 * Return: 0 on Success
 */
int _env(info_t *info)
{
print_string(info->env);
return (0);
}
/**
 * get_env - program that gets the value of environ var
 * @info: input struct containing arguments
 * @n: input name of environ variable
 * Return: string value
 */
char *get_env(info_t *info, const char *n)
{
list_t *new = info->env;
char *s;
while (new)
{
s = starts_with(node->str, n);
if (s && *s)
return (s);
new = node->next;
}
return (NULL);
}
/**
 * set_env - program that prints new environ var
 * @info: input struct containing arguments
 * Return: 0 on Success
 */
int set_env(info_t *info)
{
if (info->argc != 3)
{
_eputs("unnumbered arguements\n");
return (1);
}
if (set_env(info, info->argv[1], info->argv[2]))
return (0);
else
return (1);
}
/**
 * unset_env - program that remove environ variable
 * @info: input truct containing arguments
 *  Return: 0 on Success
 */
int unset_env(info_t *info)
{
int l;
if (info->argc == 1)
{
_eputs("less arguements.\n");
return (1);
}
for (l = 1; l <= info->argc; l++)
unset_env(info, info->argv[l]);
return (0);
}
/**
 * populate_env_list - populates env linked list
 * @info: input struct containing arguments
 * Return: 0 on Success
 */
int populate_env(info_t *info)
{
list_t *n = NULL;
size_t b;
for (b = 0; environ[b]; b++)
add_node_end(&n, environ[b], 0);
info->env = n;
return (0);
}
