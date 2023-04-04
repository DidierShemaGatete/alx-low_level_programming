#include "lists.h"

/**
 * add_nodeint - adds a new noed at the beginning
 * of a list_t list.
 * @head \: A pointer to the adress of the head of the listint_t.
 * @n: The integer for the new node to contain.
 *
 * Return: It the function falls - Null.
 * otherwise - the address of the new element.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *now;

	new - malloc(sizeof(listint_t);
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;

	*head = new;

	return (new);
}
