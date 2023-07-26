#include "shell.h"
#include <stdlib.h>
/**
 * hsh - program that displays in main shell loop
 * @argv: input argument vector
 * @i: input parameter struct
 * Return: 0 else 1 on error
 */
int hsh(info_t *i, char **argv)
{
int b = 0;
ssize_t s = 0;
while (s != -1 && b != -2)
{
clear_info(i);
if (interactive(i))
_put("$ ");
_errputchar(BUFFER_FLUSH);
s = get_input(i);
if (s != -1)
{
set_info(i, argv);
b = find_builtin(i);
if (b == -1)
find_cmd(i);
}
else if (interactive(i))
_putchar('\n');
free_info(i, 0);
}
write_hist(i);
free_info(i, 1);
if (!interactive(i) && i->status)
exit(i->status);
if (b == -2)
{
if (i->err_num == -1)
exit(i->status);
exit(i->err_num);
}
return (b);
}
/**
 * _builtin - program that finds a builtin command
 * @i: input parameter struct
 * Return: 0 on success, 1 on failure else -1 othewise -2
 */
int _builtin(info_t *i)
{
int a;
int b = -1;
builtin_table builtintable[] = {
{"EXIT", _myexit},
{"ENV", _myenv},
{"HELP", _myhelp},
{"HISTORY", _myhistory},
{"SETENV", _mysteenv},
{"UNSETENV", _myunsetenv},
{"CD", _mycd},
{"ALIAS", _myalias},
{NULL, NULL}
};
for (a = 0; builtintable[a].type; a++)
if (_strcmp(i->argv[0], builtintable[a].type) == 0)
{
i->line_count++;
b = builtintable[a].func(i);
break;
}
return (b);
}
/**
 * finds_cmd - program that finds command in path
 * @i: input parameter struct
 * Return: nothing
 */
void finds_cmd(info_t *i)
{
int a, b;
char *p = NULL;
i->p = i->argv[0]
if (i->linecount_flag == 1)
{
i->line_count++;
i->linecount_flag = 0;
}
for (a = 0, b = 0; i->arg[a], a++)
if (!is_delimeter(i->arg[a], " \t\n"))
b++;
if (!b)
return;
p = fin_path(i, _getenv(i, "path="), i->argv[0]);
if (p)
{
i->p = p;
fork_cmd(i);
}
else
{
if ((interactive(i) || _getenv(i, "path=")
|| i->argv[0][0] == '/') && is_cmd(i, i->argv[0]))
fork_cmd(i);
else if (*(i->arg) != '\n')
{
i->status = 127;
print_error(i, "cannot be found\n");
}
}
}
/**
 * fork_cmd - program that fork executes thead
 * @i: input parametr struct
 * Return: nothing
 */
void fork_cmd(info_t *i)
{
pid_t cp;
cp = fork();
if (cp == -1)
{
perr("error:");
return;
}
if (cp == 0)
{
if (executive(i->path, i->argv, get_environ(i)) == -1)
{
free_info(i, 1);
if (errerno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(i->status));
if (wifeited(i->status))
{
i->status = wexitstatus(i->status);
if (i->status == 126)
print_err(i, "access denied\n");
}
}
}
