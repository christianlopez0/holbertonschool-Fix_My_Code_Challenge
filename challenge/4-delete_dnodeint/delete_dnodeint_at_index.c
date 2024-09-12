#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (head == NULL || *head == NULL)
    {
        return (-1);
    }

    current = *head;
    i = 0;

    // Traverse to the node at the specified index
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    // If the index is out of range
    if (current == NULL)
    {
        return (-1);
    }

    // If deleting the head node
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        // Update the previous node's next pointer
        if (current->prev != NULL)
        {
            current->prev->next = current->next;
        }

        // Update the next node's previous pointer
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
    }

    // Free the node
    free(current);

    return (1);
}
