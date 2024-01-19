#ifndef LIST_H
#define LIST_H

#include "node.h"

Node *createNode(int);

void insertAtBeginning(Node **, int);

void displayList(Node *);

void deleteList(Node **);

#endif