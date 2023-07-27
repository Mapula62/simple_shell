#include <stdlib.h>
#include "shell.h"
/**
 * _exit - program that exits shell
 * @info: input structure arguments
 * Return: exits at a given status
 */
int _exit(info_t *info)
{
int exits;
if (info->argv[1])
{
exits = _erratoi(info->argv[1]);
if (exits == -1)
{
info->status = 2;
print_error(info, "unwanted num: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->error_num = _erratoi(info->argv[1]);
return (-2);
}
info->error_num = -1;
return (-2);
}
/**
 * _cd - program that changes the current dir
 * @info: input structure arguments
 * Return: 0 on Success
 */
int _cd(info_t *info)
{
char *p, *d, buf[1024];
int cd_r;
p = getcwd(buf, 1024);
if (!p)
_puts("TODO: >>getcwd unsuccessful emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!d)
cd_r = /* TODO: what must this be? */
cd((d = _getenv(info, "PWD=")) ? d : "/");
else
cd_r = cd(d);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(_getenv(info,"OLDPWD=")), _putchar('\n');
cd_r = /* TODO: what must this be? */
cd((d = _getenv(info, "OLDPWD=")) ? d : "/");
}
else
cd_r = cd(info->argv[1]);
if (cd_r == -1)
{
print_error(info, "not able to cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buf, 1024));
}
return (0);
}
/**
 * _help - program that changes the current dir
 * @info: input structure arguments
 * Return: 0 on Success
 */
int _help(info_t *info)
{
char **a;
a = info->argv;
_puts("help call works. function is not implemented yet \n");
if (0)
_puts(*a);
return (0);
}
