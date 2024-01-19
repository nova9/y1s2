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
  Node *new = malloc(sizeof(Node));
  new->key = key;
  new->right = NULL;
  new->right = NULL;
  return new;
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
  else if (key > root->key)
  {
    root->right = insert(root->right, key);
  }
  return root;
}

void preorder(Node *root)
{
  if (root == NULL) {
    return;
  }
  preorder(root->left);
  printf("%d ", root->key);
  preorder(root->right);
}

int main()
{
  Node *root = NULL;

  root = insert(root, 6);
  root = insert(root, 5);
  root = insert(root, 7);
  root = insert(root, 7);

  preorder(root);
}