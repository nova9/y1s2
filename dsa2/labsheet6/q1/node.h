#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
struct Node {
    int data;
    Node* next;
};

#endif