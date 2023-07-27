#include <stdlib.h>
#include "shell.h"
/**
 * is_chain - program that checks chain delimeter
 * @info: input parameter structure
 * @b: input character buf
 * @pos: input current position
 * Return: 1 otherwise 0
 */
int is_chain(info_t *info, char *b, size_t *pos)
{
size_t d = *s;
if (b[d] == '|' && b[d + 1] == '|')
{
b[d] = 0;
d++;
info->cmd_buf_type = CMD_OR;
}
else if (b[d] == '&' && b[d + 1] == '&')
{
b[d] = 0;
d++;
info->cmd_buf_type = CMD_AND;
}
else if (b[d] == ';')
{
b[d] = 0; /* replaces semicolon by NULL */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*s = d;
return (1);
}
/**
 * _chain - program that checks last chain
 * @info: input parameter structure
 * @b: input character buffer
 * @pos: input current position
 * @n: input starting positin
 * @length: input length
 * Return: nothing
 */
void _chain(info_t *info, char *b, size_t *pos, size_t n, size_t length)
{
size_t a = *s;
if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
b[n] = 0;
a = length;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
b[n] = 0;
a = length;
}
}
*s = a;
}
/**
 * replace_alias - program that replaces an alias
 * @info: input parameter structure
 * Return: 1 else 0
 */
int replace_alias(info_t *info)
{
int a;
list_t *new;
char *s;
for (a = 0; a < 10; a++)
{
new = node_starts_with(info->alias, info->argv[0], '=');
if (!new)
return (0);
free(info->argv[0]);
s = _strchr(node->str, '=');
if (!s)
return (0);
s = _strdup(p + 1);
if (!s)
return (0);
info->argv[0] = s;
}
return (1);
}
/**
 * replace_variables - program that replaces variables
 * @info: input parameter structure
 * Return: 1 else 0
 */
int replace_variables(info_t *info)
{
int a = 0;
list_t *new;
for (a = 0; info->argv[a]; a++)
{
if (info->argv[a][0] != '$' || !info->argv[a][1])
continue;
if (!_strcmp(info->argv[a], "$?"))
{
replace_string(&(info->argv[a]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[a], "$$"))
{
replace_string(&(info->argv[a]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
new = node_starts_with(info->env, &info->argv[a][1], '=');
if (new)
{
replace_string(&(info->argv[a]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[a], _strdup(""));
}
return (0);
}
/**
 * replace_string - program replaces string
 * @o: input old string
 * @n: input new string
 * Return: 1 else 0
 */
int replace_string(char **o, char *n)
{
free(*o);
*o = n;
return (1);
}
