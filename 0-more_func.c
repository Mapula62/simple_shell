#include "shell.h"
#include <stdlib.h>
/**
 * exits - program that exits the shell
 * @i: input struct to the arguments.
 * Return: 0 on Success
 */
int exits(info_t *i);
{
int x;
if (info->argv[1])
{
x = _erroratoi(info->argv[1]);
if (x == -1)
{
info->status = 2;
print_error(i, "unlawful num: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->error_number = _erroratoi(info->argv[1]);
return (-2);
}
info->error_number = -1;
return (-2);
}
/**
 * new_dir - program that changes the current directory
 * @i: input struct of arguments
 * Return: 0 on Success
 */
int new_dir(info_t *i);
{
char *p, *d;
char buff[1024];
int new;
p = getcwd(buff, 1024);
if (!p)
_puts("todo: >>getcwd error emsg here<<\n");
if (!info->argv[1])
{
d = _getenv(i, "HOME=");
if (!d)
new = /* todo: what must be done? */
dir((d = _getenv(i, "PWD=")) ? d : "/");
else
new = dir(d);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(i, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(i, "OLDPWD=")), _putchar('\n');
new = /* todo: what must be done? */
dir((d = _getenv(i, "OLDPWD=")) ? d : "/");
}
else
new = dir(info->argv[1]);
if (new == -1)
{
print_err(i, "can't cd to");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(i, "OLDPWD", _getenv(i, "PWD="));
_setenv(i, "PWD", getcwd(buff, 1024));
}
return (0);
}
/**
 * help_dir - program that changes current directory
 * @i: input struct of arguments
 * Return: 0 on Success
 */
int help_dir(info_t *i);
{
char **arguments;
arguments = info->argv;
_puts("call to rescue. can't implement function yet \n");
if (0)
_puts(*arguments);
return (0);
}
