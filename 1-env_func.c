#include <stdlib.h>
#include "shell.h"
/**
 * get_env - program that returns string array
 * @info: input struct arguments
 * Return: 0 on Success
 */
char **get_env(info_t *info)
{
if (!info->env || info->env_changed)
{
info->env = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->env);
}
/**
 * unset_env - program that removes environ var
 * @info: input struct containing arguments
 * Return: 1 else 0
 */
int unset_env(info_t *info, char *variable)
{
list_t *new = info->env;
size_t t = 0;
char *s;
if (!new || !variable)
return (0);
while (new)
{
s = starts_with(node->str, variable);
if (s && *s == '=')
{
info->env_changed = delete_node_at_index(&(info->env), t);
t = 0;
new = info->env;
continue;
}
new = node->next;
t++;
}
return (info->env_changed);
}
/**
 * set_env - program that sets new environ var
 * @info: input struct containing arguments
 * @variable: input string of a variable
 * @v: input value of a string
 * Return: 0 on Success
 */
int set_env(info_t *info, char *variable, char *v)
{
char *buffer = NULL;
list_t *n;
char *s;
if (!variable || !v)
return (0);
buffer = malloc(_strlen(variable) + _strlen(v) + 2);
if (!buffer)
return (1);
_strcpy(buffer, variable);
_strcat(buffer, "=");
_strcat(buffer, v);
n = info->env;
while (n)
{
s = starts_with(node->str, variable);
if (s && *s == '=')
{
free(node->str);
node->str = buffer;
info->env_changed = 1;
return (0);
}
n = node->next;
}
add_node_end(&(info->env), buffer, 0);
free(buffer);
info->env_changed = 1;
return (0);
}
