typedef struct Node Node;
struct Node
{
    int data;
    Node *next;
};

Node *createNode(int);