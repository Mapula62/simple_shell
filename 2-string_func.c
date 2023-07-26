#include "shell.h"
#include <stdlib.h>
/**
 * _chain - program that test current character in buffer
 * @i: input parameter structure
 * @b: input character buffer
 * @pos: input address of current position
 * Return: 1 otherwise 0
 */
int _chain(info_t *i, char *b, size_t *pos)
{
size_t c = *s;
if (buf[c] == '|' && b[c + 1] == '|')
{
buf[c] = 0;
c++;
i->cmd_buf_type = CMD_OR;
}
else if (b[c] == '&' && b[c + 1] == '&')
{
b[c] = 0;
c++;
i->cmd_buf_type = CMD_AND;
}
else if (b[c] == ';')
{
buf[c] = 0;
i->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*s = c;
return (1);
}
/**
 * cchain - program that checks chain base
 * @i: input parameter structure
 * @b: input character buffer
 * @pos: input address of current position
 * @a: input position
 * @n: input length
 * Return: nothing
 */
void cchain(info_t *i, char *b, size_t *pos, size_t a, size_t n)
{
size_t c = *s;
if (i->cmd_buf_type == CMD_AND)
{
if (i->status)
{
b[c] = 0;
c = n;
}
}
if (i->cmd_buf_type == CMD_OR)
{
if (!i->status)
{
b[c] = 0;
c = n;
}
}
*s = c;
}
/**
 * ralias - program thata replaces an alias
 * @i: input parameter structure
 * Return: 1 otherwise 0
 */
int ralias(info_t *i)
{
int a;
list_t *new;
char *c;
for (a = 0; a < 10; a++)
{
new = node_starts_with(i->alias, i->argv[0], '=');
if (!new)
return (0);
free(i->argv[0]);
c = _strchr(new->str, '=');
if (!c)
return (0);
c = _strdup(c + 1);
if (!c)
return (0);
i->argv[0] = c;
}
return (1);
}
/**
 * rvars - program that replaces variables
 * @info: the parameter struct
 * Return: 1 otherwise 0
 */
int rvars(info_t *i)
{
int a = 0;
list_t *new;
for (a = 0; i->argv[a]; a++)
{
if (i->argv[a][0] != '$' || !i->argv[a][1])
continue;
if (!_strcmp(i->argv[a], "$?"))
{
rstring(&(i->argv[a]),
_strdup(convert_number(i->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[a], "$$"))
{
rstring(&(i->argv[a]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
new = node_starts_with(i->env, &i->argv[a][1], '=');
if (new)
{
rstring(&(i->argv[a]),
_strdup(_strchr(new->str, '=') + 1));
continue;
}
rstring(&i->argv[a], _strdup(""));
}
return (0);
}
/**
 * rstring - program that replaces string
 * @o: input old string
 * @n: input new string
 * Return: 1 otherwise 0
 */
int rstring(char **o, char *n)
{
free(*o);
*o = n;
return (1);
}
