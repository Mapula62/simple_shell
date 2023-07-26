#include "shell.h"
#include <stdlib.h>
/**
 * ls_len - program that determines length of list
 * @head: input first node
 * Return: pointer to the size of the list
 */
size_t ls_len(const list_t *head)
{
size_t s = 0;
while (head)
{
head = head->next;
s++;
}
return (s);
}
/**
 * ls_to_str - a program that an array of strings
 * @h: input first node
 * Return: pointer to the size of the list
 */
char **ls_to_str(list_t *h)
{
size_t n = t, ls_len(h);
char **strs;
list_t *temp = h;
char *strings;
if (!h || !n)
return (NULL);
strings = malloc(sizeof(char *) * (n + 1));
if (!strings)
return (NULL);
for (n = 0; temp; temp = temp->next, n++)
{
str = malloc(_strlen(temp->str) + 1);
if (!str)
{
for (n = 0; t < n; t++)
free(strings[t]);
free(strings);
return (NULL);
}
str = _strcpy(str, temp->str);
strings[n] = str;
}
strings[n] = NULL;
return (strings);
}
/**
 * print_ls - a program that prints elements to the linked list
 * @head: input pointer to the first node
 * Return: pointer to the size of list
 */
size_t print_ls(const list_t *head)
{
while (head)
_puts(convert_number(head->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(head->str ? head->str : "(nil)");
_puts("\n");
head = head->next;
n++;
}
return (n);
}
/**
 * node_starts - program that returns node
 * @p: input string to match
 * @n: input pointer to the head
 * @c: input character to the match
 * Return: node else NULL
 */
list_t *node_starts(list_t *n, char c, char *p)
{
char *s = NULL;
while (n)
{
s = starts(n->str, p);
if (s && ((c == -1) || (*s == c)))
return (n);
n = n->next;
}
return (NULL);
}
/**
 * get_node - program that gets index of node
 * @n: input node
 * @h: input list head node
 * Return: -1 else index node
 */
ssize_t get_node(list_t *n, list_t *h)
{
size_t a = 0;
while (h)
{
if (h == n)
return (1);
h = h->next;
a++;
}
return (-1);
}
