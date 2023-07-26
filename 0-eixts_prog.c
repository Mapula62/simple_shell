#include "shell.h"
#include <stdlib.h>
/**
 * _exits - program that exits shell
 * @i: input arguments struct
 * Return: exit status
 */
int _exits(info_t *i)
{
if (i->argv[1])
{
exitscheck = erratoi(i->argv[1]);
if (exitscheck == -1)
{
i->status = 2;
print_err(i, "unwanted num: ");
_errputs(i->argv[1]);
_errputchar('\n');
return (1);
}
i->err_num = erratoi(i->argv[1]);
return (-2);
}
i->err_num = -1;
return (-2);
}
/**
 * change_dir - program that changes the cureent directory
 * @i: input argument struct
 * Return: 0 on success
 */
int change_dir(info_t *i)
{
int c;
char *dirictory, *p, buf[1024];
p = getcwd(buf, 1024);
if (!p)
_puts("todo: >>getcwd error emsg here<<\n");
if (!i->argv[1])
{
directory = _getenv(i, "home=");
if (!directory)
c = c((directory = _getenv(i, "pwd=")) ? directory : "/");
else
c = c(directory);
}
if (_strcmp(i->argv[1], "-") == 0)
{
if (!getenv(i, "oldpwd="))
{
_puts(p);
_putchar('\n');
return (1);
}
_puts(_getenv(i, "oldpwd=")), _putchar('\n');
c = c((directory = _getenv(i, "oldpwd=")) ? directory : "/");
}
else
c = c(i->argv[1]);
if (c == -1)
{
print_err(i, "cannot change diretory to ");
_errputs(i->argv[1]), _errputchar('\n');
}
else
{
_strenv(i, "oldpwd", _getenv(i, "pwd="));
_setenv(i, "pwd", getcwd(buf, 1024));
}
return (0);
}
/**
 * place_changes -  program thet changes current directory
 * @i: input argument struct
 * Return: 0 on success
 */
int place_changes(info_t *i)
{
char **arg_arr;
arg_arr = i->argv;
_puts("please change dir. function to be created \n");
if (0)
_puts(*arg_arr);
return (0);
}
