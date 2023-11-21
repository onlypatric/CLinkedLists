#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Node structure
struct node
{
    char *data; // Change from char data[MAX_STRING_LENGTH];
    struct node *next;
};

// Function prototypes
size_t calculateListSizeInBytes(struct node *startNode);
int calculateListSize(struct node *startNode);
void appendN(struct node *currentNode, const char *newData, struct node *newNext);
void append(struct node *currentNode, const char *newData);
struct node *getNodeAtIndex(struct node *startNode, int index);
int removeNodeAtIndex(struct node **startNode, int index);
void displayList(struct node *startNode);
void clearList(struct node *startNode);

int main()
{
    // Initialize an empty linked list
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    head->data = strdup("Node 1"); // Use strdup to duplicate the string

    char formattedString[256];
    char *text = "Node %d";

    for (int i = 2; i <= pow(2,10); ++i)
    {
        // Format the string with the loop variable at the end
        snprintf(formattedString, sizeof(formattedString), text, i);

        // Append the formatted string to the list
        append(head, formattedString);
    }

    displayList(head);

    // Calculate and print the size of the linked list
    int listSize = calculateListSize(head);
    printf("\nSize of the Linked List: %d\n", listSize);
    // Calculate and print the size of the linked list in bytes
    double listSizeInBytes = (int)calculateListSizeInBytes(head)/1024.0;
    printf("\nSize of the Linked List: %.2fKb\n", listSizeInBytes);

    // Don't forget to free the memory allocated for the list
    clearList(head);
}

// Append Function
void appendN(struct node *startNode, const char *newData, struct node *newNext)
{
    // Find the last node
    struct node *currentNode = startNode;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = strdup(newData);
    newNode->next = newNext;

    // Append the new node at the end
    currentNode->next = newNode;
}

// Append Function
void append(struct node *startNode, const char *newData)
{
    // Find the last node
    struct node *currentNode = startNode;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = strdup(newData);
    newNode->next = NULL;

    // Append the new node at the end
    currentNode->next = newNode;
}

// Get Function
struct node *getNodeAtIndex(struct node *startNode, int index)
{
    int currentIndex = 0;
    struct node *currentNode = startNode;

    while (currentNode != NULL && currentIndex < index)
    {
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentIndex == index)
    {
        return currentNode;
    }
    else
    {
        // Handle error (return NULL or take other appropriate action)
        return NULL;
    }
}

// Remove Function
int removeNodeAtIndex(struct node **startNode, int index)
{
    if (*startNode == NULL || index < 0)
    {
        // Invalid parameters
        return -1;
    }

    if (index == 0)
    {
        // Remove the first node
        struct node *temp = (*startNode)->next;
        free((*startNode)->data); // Free the memory for the string
        free(*startNode);
        *startNode = temp;
        return 0;
    }

    int currentIndex = 0;
    struct node *currentNode = *startNode;
    struct node *previousNode = NULL;

    while (currentNode != NULL && currentIndex < index)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentIndex++;
    }

    if (currentIndex == index && currentNode != NULL)
    {
        // Remove the node at the given index
        previousNode->next = currentNode->next;
        free(currentNode->data); // Free the memory for the string
        free(currentNode);
        return 0;
    }
    else
    {
        // Handle error (return -1 or take other appropriate action)
        return -1;
    }
}

// Display Function
void displayList(struct node *startNode)
{
    printf("[");
    struct node *currentNode = startNode;

    while (currentNode != NULL)
    {
        printf("\n\t\"%s\"", currentNode->data);

        if (currentNode->next != NULL)
        {
            printf(", ");
        }

        currentNode = currentNode->next;
    }

    printf("\n]\n");
}

// Clear List Function
void clearList(struct node *startNode)
{
    struct node *currentNode = startNode;
    struct node *nextNode;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        free(currentNode->data); // Free the memory for the string
        free(currentNode);
        currentNode = nextNode;
    }
}
// Function to calculate the size of the linked list
int calculateListSize(struct node *startNode)
{
    int size = 0;
    struct node *currentNode = startNode;

    while (currentNode != NULL)
    {
        size++;
        currentNode = currentNode->next;
    }

    return size;
}
// Function to calculate the size of the linked list in bytes
size_t calculateListSizeInBytes(struct node *startNode)
{
    size_t size = 0;
    struct node *currentNode = startNode;

    while (currentNode != NULL)
    {
        // Include the size of the node structure and the length of the data string
        size += sizeof(struct node) + strlen(currentNode->data) + 1; // +1 for the null terminator
        currentNode = currentNode->next;
    }

    return size;
}