#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Free all nodes in a doubly linked list
 *
 * @head: Pointer to the head of the list
 *
 * Description: This function iterates through each node in the doubly
 * linked list, freeing the memory allocated for each node.
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;  // Move to the next node
        free(temp);          // Free the current node
    }
}
