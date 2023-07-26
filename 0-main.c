#include "shell.h"
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: input argument count
 * @argv: input argument vector
 * Return: 0 else 1 on error
 */
int main(int argc, char **argv)
{
int fd = 2;
info_t info[] = {INFO_INIT};
asm ("move %1, %0\n\t"
"add $3, %0"
: "=r" (fd)
: "r" (fd));
if (argc == 2)
{
fd = open(agrv[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_errputs(argv[0]);
_errputs(": 0: Can't open ");
_errputs(argv[1]);
_errputchar('\n');
_errputchar(BUFFER_FLUSH);
exit(127);
}
return (exit_failure);
}
info->readfd = fd;
}
populste_env_ls(info);
read_hist(info);
hsh(info, argv);
return (exit_success);
}
