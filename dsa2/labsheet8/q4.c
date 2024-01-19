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

int balanceFactor(Node *root)
{
  return height(root->left) - height(root->right);
}

Node *rightRotate(Node *y)
{
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  return x;
}

Node *leftRotate(Node *x)
{
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  return y;
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

  if (bf > 1 && key < root->left->key)
    return rightRotate(root);

  if (bf < -1 && key > root->right->key)
    return leftRotate(root);

  if (bf > 1 && key > root->left->key)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (bf < -1 && key < root->right->key)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
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

void preorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  printf("%d ", root->key);
  preorder(root->left);
  preorder(root->right);
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

void postorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->key);
}

int main()
{
  Node *root = NULL;
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 13);
  root = insert(root, 14);
  root = insert(root, 0);
  root = insert(root, 56);
  root = insert(root, 8);

  printf("Is Balanced %d\n", isBalanced(root));

  printf("Preorder: ");
  preorder(root);
  printf("\n");

  printf("Inorder: ");
  inorder(root);
  printf("\n");

  printf("Postorder: ");
  postorder(root);
  printf("\n");
}
