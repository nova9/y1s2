#include <stdio.h>
#include <stdlib.h>
#define M 4

typedef struct Node Node;
struct Node
{
  int values[M - 1];
  Node *children[M];
};

int main()
{
  Node *root = NULL;

  root = malloc(sizeof(Node));

  root->children[3] = NULL;
}