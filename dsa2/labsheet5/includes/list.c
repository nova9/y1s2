#include "list.h"
#include <stdlib.h>

Node *createNode(int data)
{
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}