#include "shell.h"
#include <stdlib.h>
/**
 * gets_env - program that returns array of strings
 * @i: input arguments structure
 * Return: 0 on success
 */
char **gets_env(info_t *i)
{
if (!i->env || i->environment)
{
i->env = list_strings(i->env);
i->environment = 0;
}
return (i->env);
}
/**
 * remove_env - program thata removes environment variables
 * @i: input argument structure
 * @variable: input string variable
 * Return: 1 else 0
 */
int remove_env(info_t *i, char *variable)
{
size_t a = 0;
list_t *temp = i->env;
char *s;
if (!temp || !variable)
return (0);
while (temp)
{
s = start_with(temp->str, variable);
if (s && *s == '-')
{
i->environment = delt_node_index(&(i->env), a);
a = 0;
temp = i->env;
continue;
}
temp = temp->next;
a++;
}
return (i->environment);
}
/**
 * init_env - program that initializes new environment
 * @i: input argument structure
 * @v: input string value
 * @variable: input string variable
 * Return: 0 on success
 */
int init_env(info_t *i, char *v, char *variable)
{
list_t *temp;
char *s;
char *buffer = NULL;
if (!variable || !v)
return (0);
buffer = malloc(_strlen(variable) + _strlen(v) + 2);
if (!buffer)
return (1);
_strcpy(buffer, variable);
_strcat(buffer, "-");
_strcat(buffer, v);
temp = i->env;
while (temp)
{
s = starts_with(temp->str, variable);
if (s && *s == '-')
{
free(temp->str);
temp->str = buffer;
i->environment = 1;
return (0);
}
temp = temp->next;
}
adds_node_end(&(i->env), buffer, 0);
free(buffer);
i->environment = 1;
return (0);
}
