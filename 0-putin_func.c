#include <stdlib.h>
#include "shell.h"
/**
 * _history - program that displays all history list
 * @info: input struct arguments
 * Return: 0 on Success
 */
int _history(info_t *info)
{
print_list(info->history);
return (0);
}
/**
 * unset_alias - program that sets alia string
 * @info: input parameter structure
 * @str: input string alias
 * Return: 0 on Success or 1 on Failure
 */
int unset_alias(info_t *info, char *str)
{
char *s, t;
int r;
s = _strchr(str, '=');
if (!s)
return (1);
t = *s;
*s = 0;
r = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*s = t;
return (r);
}
/**
 * set_alias - program that sets alias string
 * @info: input parameter structure
 * @str: input string alias
 * Return: 0 on Success or 1 on Failure
 */
int set_alias(info_t *info, char *str)
{
char *s;
s = _strchr(str, '=');
if (!s)
return (1);
if (!*++s)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - program that prints alias string
 * @n: input alias node
 * Return: 0 on Success or 1 on Failure
 */
int print_alias(list_t *n)
{
char *s = NULL, *c = NULL;
if (n)
{
s = _strchr(node->str, '=');
for (c = node->str; c <= s; c++)
_putchar(*c);
_putchar('\'');
_puts(s + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
 * _alias - program tha mimics alias builtin
 * @info: input tructure arguments
 * Return: 0 on Success
 */
int _alias(info_t *info)
{
int d = 0;
char *s = NULL;
list_t *tenp = NULL;
if (info->argc == 1)
{
temp = info->alias;
while (temp)
{
print_alias(temp);
temp = node->next;
}
return (0);
}
for (d = 1; info->argv[d]; d++)
{
s = _strchr(info->argv[d], '=');
if (s)
set_alias(info, info->argv[d]);
else
print_alias(node_starts_with(info->alias, info->argv[d], '='));
}
return (0);
}
