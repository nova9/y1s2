#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
  int val;
  Node *left;
  Node *right;
};

Node *createNode(int key)
{
  Node *node = malloc(sizeof(Node));
  node->val = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int height(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int l = height(root->left);
  int r = height(root->right);

  return (l > r ? l : r) + 1;
}

int main()
{
  Node *root = NULL;
}
