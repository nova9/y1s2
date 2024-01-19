#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node
{
  int key;
  Node *left;
  Node *right;
};

Node *createNode(int key)
{
  Node *node = malloc(sizeof(Node));
  node->key = key;
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

bool isBalanced(Node *root)
{
  if (root == NULL)
  {
    return 1;
  }

  int lh = height(root->left);
  int rh = height(root->right);

  if (abs(lh - rh) > 1)
  {
    return 0;
  }

  bool lb = isBalanced(root->left);
  bool rb = isBalanced(root->right);

  return lb && rb;
}

int main()
{
  Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);

  printf("Height %d\n", height(root));
  printf("Balanced %d\n", isBalanced(root));
}