#include <stdio.h>
#include <stdlib.h>

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

int balanceFactor(Node *root){
  return height(root->left - root->right);
}

Node *insert(Node *root, int key)
{
  if (root == NULL)
  {
    return createNode(key);
  }

  if (key < root->key)
  {
    root->left = insert(root->left, key);
  }

  if (key > root->key)
  {
    root->right = insert(root->right, key);
  }

  int bf = balanceFactor(root);

  return root;
}

void inorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  inorder(root->left);
  printf("%d ", root->key);
  inorder(root->right);
}

int main()
{
  Node *root = NULL;
  root = insert(root, 2);
  root = insert(root, 3);

  inorder(root);
}
