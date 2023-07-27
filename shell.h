#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define USE_STRTOK 0
#define USE_GETLINE 0

#define CONVERT_UNSIGNED 2
#define CONVERT_LOWERCASE 1

#define CMD_CHAIN 3
#define CMD_AND 2
#define CMD_OR 1
#define CMD_NORM 0

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

/**
 * struct list str - singly linked_t lists
 * @str: a string
 * @next: pointor to the next node
 * @num: the number field
 */
typedef struct liststr
{
int num;
char *str;
struct liststr *next;
} list_t;

/**
 * struct pass info - contains pseudo-arguements to pass into a function,
 * allows uniform prototype for function point structure
 * @environ_changed: changes environ
 * @environ: linked_t lists local copy of environ
 * @environ: custom modifies copy of environ from LL env
 * @fname: the program filename
 * @history: the history node
 * @status: the return status of the last exec'd command
 * @alias: the alias node
 * @linecount_flag: if on count this line of input
 * @argc: the argument count
 * @err_num: the error code for exit()s
 * @histcount: the history line number count
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @line_count: the error count
 * @argv:an array of strings generated from arg
 * @readfd: the fd from which to read line input
 * @path: a string path for the current command
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @arg: a string generated from getline containing arguements
 */

typedef struct passinfo
{
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
char *fname;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;
char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
int cmd_buf_type; /* CMD_type ||, &&, ; */
int readfd;
int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
int _history(info_t *);
int _alias(info_t *);
char *get_env(info_t *, const char *);
int _env(info_t *);
int set_env(info_t *);
int unset_env(info_t *);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
int populate_env(info_t *);
char **get_env(info_t *);
int unset_env(info_t *, char *);
int set_env(info_t *, char *, char *);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
int _exit(info_t *);
int _cd(info_t *);
int _help(info_t *);
int is_chain(info_t *, char *, size_t *);
void _chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
int _putchar(char c);
int _chain(info_t *i, char *buffer, size_t *position);
void commd_chain(info_t *i, char *buffer, size_t *pos, size_t n, size_t length);
int replace_alias(info_t *i);
int replace_var(info_t *i);
int replace_string(char **o, char *n);
int _exits(info_t *i);
int change_dir(info_t *i);
int place_changes(info_t *i);
int _environ(info_t *i);
char *gets_environ(info_t *i, const char *n);
int init_environ(info_t *i);
int remove_environ(info_t *i);
int popul_environ(info_t *i);
list_t *add_node(const char *str, list_t **h, int n);
list_t *node_end(const char *str, list_t **h, int n);
size_t list_str(const list_t *head);
int delete_node(unsigned int i, list_t **h);
void frees_list(list_t **h_prt);
int main(int argc, char **argv);
char *_memset(char *size, unsigned int num, char b);
void _free(char **sl);
void *_realloc(void *p, unsigned int n, unsigned int o);
char *hist_file(info_t *i);
int write_hist(info_t *i);
int read_hist(info_t *i);
int build_hist(info_t *i, char buffer, int c);
int renumber_hist(info_t *i);
int _strlen(char *size);
int _strcmp(char *s, char *n);
char *starts_with(const char *needle, const char *haystack);
char *_strcat(char *src, char *dest);
ssize_t buf(info_t *i, size_t *l, char **buffer)
ssize_t _gets(info_t *i);
ssize_t _reads(info_t *i, char *buffer, size_t *s);
int _getsline(info_t *i, size_t *l, char **p);
void siginHandler(__attribute__((unused))int sn);
char **gets_env(info_t *i);
int remove_env(info_t *i, char *variable);
int init_env(info_t *i, char *v, char *variable);
int _history(info_t *i);
int unset_alias(info_t *i, char *str);
int set_alias(info_t *i, char *str);
int prints_alias(list_t *n);
int _alias(info_t *i);
size_t ls_len(const list_t *head);
char **ls_to_str(list_t *h);
size_t print_ls(const list_t *head);
list_t *node_starts(list_t *n, char c, char *p);
ssize_t get_node(list_t *n, list_t *h);
int _free(void **t);
char *_strcpy(char *src, char *dest);
char *_strdup(const char *str);
void _puts(char *str);
void _errputs(char *str);
int _errputchar(char z);
int _putsfd(int fd, char z);
int _putfd(int fd, char *str);
int _interac(info_t *n);
int _delimeter(char *d, char n);
int _isalpha(int n);
int _atoi(char *size);
char *_strncpy(char *src, char *dest, int n);
char *_strncat(char *src, char *dest, int n);
char *_strchr(char *s, char c);
int error_atoi(char *size);
void prt_error(char *errstr, info_t *n);
int prt_d(int i, int fd);
char *conv_num(int f, int b, long int n);
void remove_com(char *b);
char **strtow(char *str, char *s);
char **next_strtow(char *str, char s);
int _command(info_t *i, char *p);
char *duplicates_chr(char * *pstr, int str, int stp);
char *find_path(info_t *i, char *pstr, char *command);
void checks_chain(info_t *i, char *buffer, size_t *pos, size_t n, size_t l);
void initializes(info_t *i);
void get_info(info_t *i, char **argv);
void frees_info(info_t *i, int total);
int hsh(info_t *i, char **argv);
int _builtin(info_t *i);
void finds_cmd(info_t *i);
void fork_cmd(info_t *i);

#endif
