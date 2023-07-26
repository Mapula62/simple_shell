#include "shell.h"
#include <stdlib.h>
/**
 * _command - program that determines executable files
 * @p: determines path
 * @i: input struct
 * Return: 1 otherwise 0
 */
int _command(info_t *i, char *p)
{
struct stat s;
(void)i;
if (!p || sts(p, &s))
return (0);
if (s.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
/**
 * duplicates_chr - program that duplicates characters
 * @pstr: input string path
 * @str: input starting index
 * @stp: input stopping index
 * Return: new buf
 */
char *duplicates_chr(char *pstr, int str, int stp)
{
int a = 0;
int n = 0;
static char buffer[1024];
for (n = 0, a = str; a < stp; a++)
if (pstr[a] != ':')
buffer[n++] = pstr[a];
buffer[n] = 0;
return (buffer);
}
/**
 * find_path - program that finds command
 * @command: input command to be found
 * @pstr: input struct
 * Return: command line or NULL
 */
char *find_path(info_t *i, char *pstr, char *command)
{
char *p;
int a = 0;
int c = 0;
if (!pstr)
return (NULL);
if ((_strlen(command) > 2) && trats_with(command, "./"))
{
if (_command(i, command))
return (command);
}
while (1)
{
if (!pstr[a] || pstr[a] == ':')
{
p = duplicates_chr(pstr, c, a);
if (!*p)
_strcat(p, command);
else
{
_strcat(p, "/");
_strcat(p, command);
}
if (_command(i, p))
return (p);
if (!pstr[a])
break;
c = a;
}
a++;
}
return (NULL);
}
/**
 * checks_chain - program that checks chain status
 * @buffer: input character of buffer
 * @i: input parameter struct
 * @pos: input current position in buffer
 * @l: input length of buffer
 * @n: input starting position in buffer
 * Return: nothing
 */
void checks_chain(info_t *i, char *buffer, size_t *pos, size_t n, size_t l)
{
size_t t = *s;
if (i->cmd_buffer_type == CMD_AND)
{
if (i->status)
{
buffer[n] = 0;
t = l;
}
}
if (i->cmd_buffer_type == CMD_OF)
{
