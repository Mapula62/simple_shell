#include "shell.h"
#include <stdlib.h>
/**
 * add_node - program that adds node
 * @str: input node
 * @n: input index node
 * @h: input head node
 * Return: address of list
 */
list_t *add_node(const char *str, list_t **h, int n)
{
list_t *temp;
if (!h)
return (NULL);
temp = malloc(sizeof(list_t));
if (!temp)
return (NULL);
_memset((void *)temp, 0, sizeof(list_t));
temp->n = n;
if (str)
{
temp->str = _strdup(str);
if (!temp->str)
{
free(temp);
return (NULL);
}
}
temp->next = *h;
*h = temp;
return (temp);
}
/**
 * node_end - program that adds node to the end
 * @str: input node
 * @n: input index node
 * @h: input head node
 * Return: address of the size of the list
 */
list_t *node_end(const char *str, list_t **h, int n)
{
list_t *node, *temp;
if (!h)
return (NULL);
temp = *h;
node = malloc(sizeof(list_t));
if (!node)
return (NULL);
_memset((void *)node, 0, sizeof(list_t));
if (str)
{
node->str = _strdup(str);
if (!node->str)
{
free(node);
return (NULL);
}
}
if (temp)
{
while (temp->next)
temp = temp->next;
temp->next = node;
}
else
*h = node;
return (node);
}
/**
 * list_str - program that prints list_t linked list
 * @head: input first node pointer
 * Return: address of the size of the list
 */
size_t list_str(const list_t *head)
{
size_t r = 0;
while (head)
{
_puts(head->str ? head->str : "(nil)");
_puts("\n");
head = head->next;
r++;
}
return (r);
}
/**
 * delete_node - program that deletes index node
 * @i: input index node to be deleted
 * @h: input first node
 * Return: 1 else 0
 */
int delete_node(unsigned int i, list_t **h)
{
unsigned int n = 0;
list_t *temp, *node;
if (!h || !*h)
return (0);
if (!i)
{
temp = *h;
*h = (*h)->next;
free(temp->str);
free(temp);
return (1);
}
temp = *h;
while (temp)
{
node->next = temp->next;
free(temp->next);
free(temp);
return  (1);
}
n++;
node = temp;
temp = temp->next;
}
return (0);
}
/**
 * frees_list - a program that frees all nodes
 * @h_prt: input pointer to the head node
 * Return: nothing
 */
void frees_list(list_t **h_prt)
{
list_t *n, *temp, *h;
if (!h_ptr || !*h_ptr)
return;
h = *h_ptr;
n = h;
while (n)
{
temp = n->next;
free(n->str);
free(n);
n = temp;
}
*h = NULL;
}
