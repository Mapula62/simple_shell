#include "shell.h"
#include <stdlib.h>
/**
 * _history - program that displays history list
 * @i: input argument struct
 * Return: 0 on success
 */
int _history(info_t *i)
{
print_list(i->history);
return (0);
}
/**
 * unset_alias - program that removes alias
 * @str: input string alias
 * @i: input parameter struct
 * Return: 0 else 1 on failure
 */
int unset_alias(info_t *i, char *str)
{
int r;
char *s, t;
s = _strchr(str, '=');
if (!s)
return (1);
t = *s;
*s = 0;
r = delete_node_index(&(i->alias),
get_node_index(i->alias, node_starts_with(i->alias, str, -1)));
*s = t;
return (r);
}
/**
 * set_alias - program that sets alias
 * @str: input string alias
* @i: input parameter struct
 * Return: 0 else 1 on failure
 */
int set_alias(info_t *i, char *str)
{
char *s;
s = strchr(str, '=');
if (!*++s)
return (unset_alias(i, str));
unset_alias(i, str);
return (add_node_end(&(i->alias), str, 0) == NULL);
}
/**
 * prints_alias - program that prints alias string
 * @n: input alias node
 * Return: 0 else 1 if failure
 */
int prints_alias(list_t *n)
{
char *s = NULL;
char *l = NULL;
if (n)
{
s = _strchr(n->str, '=');
for (l = n->str; l <= s; l++)
_putchar(*l);
_putchar('\'');
_puts(s + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
 * _alias - program that inputs mimics
 * @i: input argument struct
 * Return: 0 on success
 */
int _alias(info_t *i)
{
list_t *n = NULL;
char *s = NULL;
int a = 0;
if (i->argc == 1)
{
n = i->alias;
while (n)
{
print_alias(n);
n = n->next;
}
return (0);
}
for  (a = 1; i->argv[a]; a++)
{
s = _strchr(i->argv[a], '=');
if (s)
set_alias(i, i->argv[a]);
else
print_alias(node_starts_with(i->alias, i->argv[a], '='));
}
return (0);
}
