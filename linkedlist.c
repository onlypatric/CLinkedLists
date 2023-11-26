#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct Node
 * @brief Represents a node in the linked list.
 */
typedef struct Node
{
    char *data;        /**< Data stored in the node (char*) */
    struct Node *next; /**< Pointer to the next node in the list */
} Node;

/**
 * @struct LinkedList
 * @brief Represents a linked list.
 */
typedef struct
{
    Node *head; /**< Pointer to the first node in the list */
} LinkedList;

/**
 * @brief Initializes an empty linked list.
 * @param list The linked list to initialize.
 */
void initializeList(LinkedList *list)
{
    list->head = NULL;
}

/**
 * @brief Appends a new node with the given data to the end of the linked list.
 * @param list The linked list.
 * @param data The data to be stored in the new node.
 * @return 0 on success, -2 on error.
 */
int appendNode(LinkedList *list, const char *data)
{
    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return -2; // Memory allocation error
    }

    // Allocate memory for data and copy it
    newNode->data = strdup(data);
    if (newNode->data == NULL)
    {
        free(newNode);
        return -2; // Memory allocation error
    }

    newNode->next = NULL; // The new node will be the last one

    // If the list is empty, the new node becomes the head
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        // Find the last node and link the new node
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    return 0; // Success
}

/**
 * @brief Inserts a new node with the given data at the specified position in the linked list.
 * @param list The linked list.
 * @param data The data to be stored in the new node.
 * @param position The position at which to insert the new node (-1 to append at the end).
 * @return 0 on success, -1 if out of bounds, -2 on error.
 */
int insertNode(LinkedList *list, const char *data, int position)
{
    // Handle the case to append at the end
    if (position == -1)
    {
        return appendNode(list, data);
    }

    // Check if the position is out of bounds
    if (position < 0)
    {
        return -1;
    }

    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return -2; // Memory allocation error
    }

    // Allocate memory for data and copy it
    newNode->data = strdup(data);
    if (newNode->data == NULL)
    {
        free(newNode);
        return -2; // Memory allocation error
    }

    // If inserting at the beginning
    if (position == 0)
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    else
    {
        // Find the node before the specified position
        Node *current = list->head;
        for (int i = 1; i < position; ++i)
        {
            if (current == NULL)
            {
                free(newNode->data);
                free(newNode);
                return -1; // Out of bounds
            }
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    return 0; // Success
}

/**
 * @brief Removes a node at the specified position and allocates its data to the given char*.
 * @param list The linked list.
 * @param position The position of the node to remove.
 * @param dataPtr A pointer to a char* to store the removed data.
 * @return 0 on success, -1 if out of bounds, -2 on error.
 */
int removeNode(LinkedList *list, int position, char **dataPtr)
{
    // Check if the position is out of bounds
    if (position < 0)
    {
        return -1;
    }

    // If removing the first node
    if (position == 0)
    {
        if (list->head == NULL)
        {
            return -1; // Out of bounds
        }
        Node *temp = list->head;
        *dataPtr = temp->data;
        list->head = list->head->next;
        free(temp);
    }
    else
    {
        // Find the node before the specified position
        Node *current = list->head;
        for (int i = 1; i < position; ++i)
        {
            if (current == NULL || current->next == NULL)
            {
                return -1; // Out of bounds
            }
            current = current->next;
        }

        // Remove the node and allocate its data
        Node *temp = current->next;
        *dataPtr = temp->data;
        current->next = temp->next;
        free(temp);
    }

    return 0; // Success
}

/**
 * @brief Removes a node at the specified position without returning its data.
 * @param list The linked list.
 * @param position The position of the node to remove.
 * @return 0 on success, -1 if out of bounds, -2 on error.
 */
int removeNodeWithoutReturn(LinkedList *list, int position)
{
    // Check if the position is out of bounds
    if (position < 0)
    {
        return -1;
    }

    // If removing the first node
    if (position == 0)
    {
        if (list->head == NULL)
        {
            return -1; // Out of bounds
        }
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp->data);
        free(temp);
    }
    else
    {
        // Find the node before the specified position
        Node *current = list->head;
        for (int i = 1; i < position; ++i)
        {
            if (current == NULL || current->next == NULL)
            {
                return -1; // Out of bounds
            }
            current = current->next;
        }

        // Remove the node
        Node *temp = current->next;
        current->next = temp->next;
        free(temp->data);
        free(temp);
    }

    return 0; // Success
}

/**
 * @brief Gets the node at the specified position.
 * @param list The linked list.
 * @param position The position of the node to get.
 * @return A pointer to the node at the specified position, NULL if out of bounds.
 */
Node *getNode(LinkedList *list, int position)
{
    // Check if the position is out of bounds
    if (position < 0)
    {
        return NULL;
    }

    Node *current = list->head;

    for (int i = 0; i < position; ++i)
    {
        if (current == NULL)
        {
            return NULL; // Out of bounds
        }
        current = current->next;
    }

    return current;
}

/**
 * @brief Replaces the node at the specified position with a new node containing the given data.
 * @param list The linked list.
 * @param position The position of the node to replace.
 * @param newData The data to be stored in the new node.
 * @return 0 on success, -1 if out of bounds, -2 on error.
 */
int replaceNode(LinkedList *list, int position, const char *newData)
{
    // Check if the position is out of bounds
    if (position < 0)
    {
        return -1;
    }

    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return -2; // Memory allocation error
    }

    // Allocate memory for data and copy it
    newNode->data = strdup(newData);
    if (newNode->data == NULL)
    {
        free(newNode);
        return -2; // Memory allocation error
    }

    // If replacing the first node
    if (position == 0)
    {
        newNode->next = list->head->next;
        free(list->head->data);
        free(list->head);
        list->head = newNode;
    }
    else
    {
        // Find the node before the specified position
        Node *current = list->head;
        for (int i = 1; i < position; ++i)
        {
            if (current == NULL || current->next == NULL)
            {
                free(newNode->data);
                free(newNode);
                return -1; // Out of bounds
            }
            current = current->next;
        }

        // Replace the node
        newNode->next = current->next->next;
        free(current->next->data);
        free(current->next);
        current->next = newNode;
    }

    return 0; // Success
}

/**
 * @brief Clears the entire linked list, freeing all allocated memory.
 * @param list The linked list.
 */
void clearList(LinkedList *list)
{
    Node *current = list->head;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    list->head = NULL;
}

/**
 * @brief Prints the linked list as a string array.
 * @param list The linked list.
 */
void printList(LinkedList *list)
{
    printf("[");
    Node *current = list->head;

    while (current != NULL)
    {
        printf("\"%s\"", current->data);
        if (current->next != NULL)
        {
            printf(",");
        }
        current = current->next;
    }

    printf("]\n");
}

// Example usage:
int main()
{
    LinkedList myList;
    initializeList(&myList);

    appendNode(&myList, "node1");
    appendNode(&myList, "node2");
    insertNode(&myList, "node3", 1);
    printList(&myList);

    char *removedData;
    removeNode(&myList, 1, &removedData);
    printf("Removed Node Data: %s\n", removedData);
    free(removedData);
    printList(&myList);

    replaceNode(&myList, 0, "newNode");
    printList(&myList);

    clearList(&myList);
    printList(&myList);

    return 0;
}
