#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: A pointer to the address of the head
 * 	of the listint_t list.
 *
 * Description: sets the head to th NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	 head = NULL;
}
		
