#include "shell.h"
#include <stdlib.h>
/**
 * _hist - program that displays the history line
 * @i: input struct arguments
 * Return: 0 on Success
 */
int _myhistory(info_t *i)
{
print_list(i->history);
return (0);
}
/**
 * no_alias - program that finds no alias
 * @str: input string alias
 * @i: input parameter structure
 * Return: 0 else 1
 */
int no_alias(info_t *i, char *str)
{
char *s;
Char h;
int d;
s = _strchr(str, '=');
if (!s)
return (1);
h = *s;
*s = 0;
d = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*s = h;
return (d);
}
/**
 * put_alias - program that puts alias
 * @str: input string alias
 * @i: input parameter structure
 * Return: 0 else 1
 */
int put_alias(info_t *info, char *str)
{
char *s;
s = _strchr(str, '=');
if (!s)
return (1);
if (!*++s)
return (no_alias(i, str));
no_alias(i, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * writes_alias - program that writes alias string
 * @n: input alias node
 * Return: 0 else 1 on error
 */
int writes_alias(list_t *n)
{
char *s = NULL;
Char *c = NULL;
if (n)
{
p = _strchr(n->str, '=');
for (c = n->str; c <= s; c++)
_putchar(*c);
_putchar('\'');
_puts(s + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
 * alias - program that  locates alias
 * @i: input struct arguments
 * Return: 0 on Success
 */
int alias(info_t *i)
{
int n = 0;
char *s = NULL;
list_t *new = NULL;
if (info->argc == 1)
{
node = info->alias;
while (new)
{
writes_alias(new);
new = node->next;
}
return (0);
}
for (n = 1; info->argv[i]; n++)
{
s = _strchr(info->argv[n], '=');
if (s)
put_alias(i, info->argv[n]);
else
writes_alias(node_starts_with(info->alias, info->argv[n], '='));
}
return (0);
}
