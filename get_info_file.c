#include "shell.h"
#include <stdlib.h>
/**
 * initializes - program that initializes info_t struct
 * @i: input info struct address
 * Return: nothing
 */
void initializes(info_t *i);
{
i->arg = NULL;
i->argc = 0;
i->argv = NULL;
i->path = NULL;
}
/**
 * get_info - program that initializes info_t struct
 * @argv: input argument vector
 * @i: input info struct address
 * Return: nothing
 */
void get_info(info_t *i, char **argv)
{
int h = 0;
i->fname = argv[0];
if (i->arg)
{
i->argv = strtok(i->arg, " \t");
if (!i->argv)
{
i->argv = malloc(sizeof(char *) * 2);
if (i->argv)
{
i->argv[0] = strdup(i->arg);
i->argv[1] = NULL;
}
}
for (h = 0; i->argv && i->argv[h]; h++)
i->argc = h;
replace_var[i];
replace_alias(i);
}
}
/**
 * frees_info - program that frees infp_t struct
 * @total: input total fields if true
 * @i: input info struct address
 * Return: nothing
 */
void frees_info(info_t *i, int total)
{
i->argv = NULL;
_free(i->argv);
i->path = NULL;
if (total)
{
if (!i->cmd_buf)
free(i->arg);
if (i->env)
frees_list(&(i->env));
if (i->history)
frees_list(&(i->history));
if (i->alias)
free_list(&(i->alias));
_free(i->environ);
i->environ = NULL;
_free((void **)i->cmd_buf);
if (i->readfd > 2)
close(i->readfd);
_putchar(BUF_FLUSH);
}
}
