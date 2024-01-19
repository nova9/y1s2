#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node *createNode(int data)
{
  Node *newNode = malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *insertNode(Node *root, int data)
{
  if (root == NULL)
  {
    return createNode(data);
  }

  if (data < root->data)
  {
    root->left = insertNode(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insertNode(root->right, data);
  }

  return root;
}

void recursivePreorder(Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    recursivePreorder(root->left);
    recursivePreorder(root->right);
  }
}

void recursiveInorder(Node *root)
{
  if (root != NULL)
  {
    recursiveInorder(root->left);
    printf("%d ", root->data);
    recursiveInorder(root->right);
  }
}

void recursivePostorder(Node *root)
{
  if (root != NULL)
  {
    recursivePostorder(root->left);
    recursivePostorder(root->right);
    printf("%d ", root->data);
  }
}

int main()
{
  Node *root = NULL;
  int choice, data;

  while (1)
  {
    printf("\nBinary Tree Traversals:\n");
    printf("1. Recursive Pre-order Traversal\n");
    printf("2. Recursive In-order Traversal\n");
    printf("3. Recursive Post-order Traversal\n");
    printf("4. Insert Node\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Recursive Pre-order Traversal: ");
      recursivePreorder(root);
      printf("\n");
      break;
    case 2:
      printf("Recursive In-order Traversal: ");
      recursiveInorder(root);
      printf("\n");
      break;
    case 3:
      printf("Recursive Post-order Traversal: ");
      recursivePostorder(root);
      printf("\n");
      break;
    case 4:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      root = insertNode(root, data);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }

  return 0;
}
