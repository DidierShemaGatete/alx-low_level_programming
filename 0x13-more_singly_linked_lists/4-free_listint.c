#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: A pointer to the head of listint_t list to be freed.
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
