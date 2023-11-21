# Linked List Documentation

## Overview

This C program implements a linked list data structure using a custom `struct node` to represent individual nodes. The linked list is initialized with a head node, and various functions are provided to perform operations on the linked list.

## Functions

## `appendN`

```c
void appendN(struct node *startNode, const char*newData, struct node *newNext);
```

This function appends a new node to the end of the linked list. It takes the current start node, the data for the new node (`newData`), and a pointer to the next node (`newNext`). It iterates through the list to find the last node and appends the new node.

## `append`

```c
void append(struct node *startNode, const char*newData);
```

Similar to `appendN`, this function appends a new node to the end of the linked list. It takes the current start node and the data for the new node (`newData`). It iterates through the list to find the last node and appends the new node.

## `getNodeAtIndex`

```c
struct node *getNodeAtIndex(struct node*startNode, int index);
```

This function retrieves the node at a specified index in the linked list. It takes the current start node and the index of the desired node. It returns a pointer to the node if found, otherwise, it returns `NULL`.

## `removeNodeAtIndex`

```c
int removeNodeAtIndex(struct node **startNode, int index);
```

This function removes the node at the specified index from the linked list. It takes a pointer to the start node and the index of the node to be removed. It returns `0` on success and `-1` on failure.

## `displayList`

```c
void displayList(struct node *startNode);
```

This function displays the elements of the linked list. It takes the current start node and prints the data of each node in the list.

## `clearList`

```c
void clearList(struct node *startNode);
```

This function frees the memory allocated for the entire linked list. It takes the current start node and releases the memory for each node in the list.

## `calculateListSize`

```c
int calculateListSize(struct node *startNode);
```

This function calculates and returns the number of nodes in the linked list. It takes the current start node and returns the size of the list.

## `calculateListSizeInBytes`

```c
size_t calculateListSizeInBytes(struct node *startNode);
```

This function calculates and returns the total size of the linked list in bytes, including the size of the node structure and the length of the data string for each node. It takes the current start node and returns the size in bytes.

## Usage

The linked list is initialized in the `main` function, and various operations are performed to demonstrate the functionality of the provided functions. The memory allocated for the linked list is freed at the end to prevent memory leaks.

Make sure to include the necessary header files (`#include <stdio.h>`, `#include <stdlib.h>`, `#include <string.h>`, `#include <math.h>`) before using this code.
