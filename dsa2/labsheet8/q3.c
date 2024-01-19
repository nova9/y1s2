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

void printDepth(Node *root, int depth)
{
  if (root == NULL)
  {
    return;
  }
  printf("Node with value %d has depth %d\n", root->val, depth);
  printDepth(root->left, depth + 1);
  printDepth(root->right, depth + 1);
}

void printDOF(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  int dof = 0;
  if (root->left != NULL)
  {
    dof++;
  }
  if (root->right != NULL)
  {
    dof++;
  }

  printf("Node with value %d has degree of freedom %d\n", root->val, dof);

  printDOF(root->left);
  printDOF(root->right);
}

int main()
{
  Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);

  printf("Height of the tree: %d\n", height(root));

  printf("\nDepth of each node:\n");
  printDepth(root, 0);

  printf("\nDegree of freedom for each node:\n");
  printDOF(root);
}
