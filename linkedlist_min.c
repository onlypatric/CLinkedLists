#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { char *data; struct Node *next; } Node;
typedef struct { Node *head; } LinkedList;

void initializeList(LinkedList *list) { list->head = NULL; }
int appendNode(LinkedList *list, const char *data) {
    Node *newNode = malloc(sizeof(Node)); if (!newNode) return -2;
    newNode->data = strdup(data); if (!newNode->data) { free(newNode); return -2; }
    newNode->next = NULL; if (!list->head) list->head = newNode; else { Node *c = list->head; while (c->next) c = c->next; c->next = newNode; } return 0; }
int insertNode(LinkedList *list, const char *data, int p) {
    if (p == -1) return appendNode(list, data); if (p < 0) return -1;
    Node *newNode = malloc(sizeof(Node)); if (!newNode) return -2;
    newNode->data = strdup(data); if (!newNode->data) { free(newNode); return -2; }
    if (p == 0) { newNode->next = list->head; list->head = newNode; } else { Node *c = list->head; for (int i = 1; i < p; ++i) { if (!c || !c->next) { free(newNode->data); free(newNode); return -1; } c = c->next; } newNode->next = c->next; c->next = newNode; } return 0; }
int removeNode(LinkedList *list, int p, char **d) {
    if (p < 0) return -1; if (p == 0) { if (!list->head) return -1; Node *t = list->head; *d = t->data; list->head = list->head->next; free(t); } else { Node *c = list->head; for (int i = 1; i < p; ++i) { if (!c || !c->next) return -1; c = c->next; } Node *t = c->next; *d = t->data; c->next = t->next; free(t); } return 0; }
int removeNodeWithoutReturn(LinkedList *list, int p) {
    if (p < 0) return -1; if (p == 0) { if (!list->head) return -1; Node *t = list->head; list->head = list->head->next; free(t->data); free(t); } else { Node *c = list->head; for (int i = 1; i < p; ++i) { if (!c || !c->next) return -1; c = c->next; } Node *t = c->next; c->next = t->next; free(t->data); free(t); } return 0; }
Node *getNode(LinkedList *list, int p) {
    if (p < 0) return NULL; Node *c = list->head; for (int i = 0; i < p; ++i) { if (!c) return NULL; c = c->next; } return c; }
int replaceNode(LinkedList *list, int p, const char *nd) {
    if (p < 0) return -1;
    Node *newNode = malloc(sizeof(Node)); if (!newNode) return -2;
    newNode->data = strdup(nd); if (!newNode->data) { free(newNode); return -2; }
    if (p == 0) { newNode->next = list->head->next; free(list->head->data); free(list->head); list->head = newNode; } else { Node *c = list->head; for (int i = 1; i < p; ++i) { if (!c || !c->next) { free(newNode->data); free(newNode); return -1; } c = c->next; } newNode->next = c->next->next; free(c->next->data); free(c->next); c->next = newNode; } return 0; }
void clearList(LinkedList *list) { Node *c = list->head, *n; while (c) { n = c->next; free(c->data); free(c); c = n; } list->head = NULL; }
void printList(LinkedList *list) { printf("["); Node *c = list->head; while (c) { printf("\"%s\"", c->data); if (c->next) printf(","); c = c->next; } printf("]\n"); }

int main() {
    LinkedList myList; initializeList(&myList);
    appendNode(&myList, "node1"); appendNode(&myList, "node2"); insertNode(&myList, "node3", 1); printList(&myList);
    char *rd; removeNode(&myList, 1, &rd); printf("Removed Node Data: %s\n", rd); free(rd); printList(&myList);
    replaceNode(&myList, 0, "newNode"); printList(&myList);
    clearList(&myList); printList(&myList);
    return 0;
}
