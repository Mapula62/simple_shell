#include "shell.h"
#include <stdlib.h>
/**
 * _chain - program that tests chain delimeter
 * @buffer: input character buffer
 * @i: input parameter struct
 * @position: input current position
 * Return: 1 otherwise 0
 */
int _chain(info_t *i, char *buffer, size_t *position)
{
size_t t = *s;
if (buffer[t] == '|' && buffer[t + 1] == '|')
{
buffer[t] = 0;
t++;
i->cmd_buffer_type = CMD_OR;
}
if (buffer[t] == '&' && buffer[t + 1] == '&')
{
buffer[t] = 0;
t++;
i->cmd_buffer_type = CMD_AND;
}
else if (buffer[t] == ';')
{
buffer[t] = 0;
i->cmd_buffer_type = CMD_CHAIN;
}
else
return (0);
*s = t;
return (1);
}
/**
 * commd_chain - program that checks last status
 * @buffer: input character buffer
 * @i: input parameter struct
 * @pos: input address of current position in buffer
 * @n: input starting position in buffer
 * @length: input length of buffer
 * Return: nothing
 */
void commd_chain(info_t *i, char *buffer, size_t *pos, size_t n, size_t length)
{
size_t a = *s;
if (i->cmd_buffer_type == CMD_AND)
{
if (i->status)
{
buffer[n] = 0;
a = length;
}
}
if (i->cmd_buffer_type == CMD_OR)
{
if (!i->status)
{
buffer[n] = 0;
a = length;
}
}
*s = a;
}
/**
 * replace_alias - program that replaces an alias
 * @i: input parameter struct
 * Return: 1 else 0
 */
int replace_alias(info_t *i)

char *s;
list_t *n;
int a;
for (a = 0; a < 10; a++)
{
n = node_starts_with(i->alias, i->argv[0], '=');
if (!n)
return (0);
free(i->argv[0]);
s = _strchr(n->str, '=');
if (!s)
return (0);
s = _strdup(s + 1);
if (!s)
return (0);
i->argv[0] = s;
}
return (1);
}
/**
 * replace_var - program that replaces variables
 * @i: input parameter struct
 * Return: 1 otherwise 0
 */
int replace_var(info_t *i)
{
list_t *n;
int a = 0;
for (a = 0; i->argv[a]; a++)
{
if (i->argv[a][0] != '$' || != i->argv[a][1])
continue;
if (!_strcmp(i->argv[a], "$?"))
{
replace_string(&(i->argv[a]),
_strdup(converts_number(i->status, 10, 0)));
continue;
}
if (!_strcmp(i->argv[a], "$$"))
{
replace_string(&(i->argv[a]),
_strdup(converts_number(getpid(), 10, 0)));
continue;
}
n = node_stars_with(i->env, &i->argv[a][1], '=');
if (n)
{
replace_string(&(i->argv[a]),
_strdup(_strchr(n->str, '=') + 1));
continue;
}
replace_string(&(i->argv[a], _strdup(""));
}
return (0);
}
/**
 * replace_string - program that replace a string
 * @n: input new string
 * @o: input address of old string
 * Return: 1 else 0
 */
int replace_string(char **o, char *n)
{
free(*o);
*o = n;
return (1);
}
