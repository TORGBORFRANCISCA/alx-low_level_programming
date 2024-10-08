#include "lists.h"
/**
 * add_dnodeint_end - adds new node at the end of a list.
 * @head: current head address
 * @n: number to fill node
 * Return: number of nodes.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *last = *head;
	/* In case it isn't imput a head*/
	if (head == NULL)
		return (NULL);
	/*Allocate new node*/
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	/*Assign info to new node*/
	new_node->n = n;
	new_node->next = NULL;
	/*Assign the head if list is empty*/
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}
	/*If list is not empty, find the last node and connect the new node*/
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;

	return (new_node);
}
