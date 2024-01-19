#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "stack.h"


Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
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


void iterativePreorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  Stack *stack = createStack(100);
  push(stack, root);

  while (!isEmpty(stack))
  {
    Node *current = pop(stack);
    printf("%d ", current->data);

    if (current->right != NULL)
    {
      push(stack, current->right);
    }
    if (current->left != NULL)
    {
      push(stack, current->left);
    }
  }

  free(stack->array);
  free(stack);
}


void iterativeInorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  Stack *stack = createStack(100);
  Node *current = root;

  while (current != NULL || !isEmpty(stack))
  {
    while (current != NULL)
    {
      push(stack, current);
      current = current->left;
    }

    current = pop(stack);
    printf("%d ", current->data);
    current = current->right;
  }

  free(stack->array);
  free(stack);
}


void iterativePostorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  Stack *stack1 = createStack(100);
  Stack *stack2 = createStack(100);
  push(stack1, root);

  while (!isEmpty(stack1))
  {
    Node *current = pop(stack1);
    push(stack2, current);

    if (current->left != NULL)
    {
      push(stack1, current->left);
    }
    if (current->right != NULL)
    {
      push(stack1, current->right);
    }
  }

  while (!isEmpty(stack2))
  {
    Node *temp = pop(stack2);
    printf("%d ", temp->data);
  }

  free(stack1->array);
  free(stack1);
  free(stack2->array);
  free(stack2);
}

int main()
{
  Node *root = NULL;
  int choice, data;

  while (1)
  {
    printf("\nBinary Tree Operations:\n");
    printf("1. Insert Node\n");
    printf("2. Recursive Pre-order Traversal\n");
    printf("3. Recursive In-order Traversal\n");
    printf("4. Recursive Post-order Traversal\n");
    printf("5. Iterative Pre-order Traversal\n");
    printf("6. Iterative In-order Traversal\n");
    printf("7. Iterative Post-order Traversal\n");
    printf("8. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      root = insertNode(root, data);
      break;
    case 2:
      printf("Recursive Pre-order Traversal: ");
      recursivePreorder(root);
      printf("\n");
      break;
    case 3:
      printf("Recursive In-order Traversal: ");
      recursiveInorder(root);
      printf("\n");
      break;
    case 4:
      printf("Recursive Post-order Traversal: ");
      recursivePostorder(root);
      printf("\n");
      break;
    case 5:
      printf("Iterative Pre-order Traversal: ");
      iterativePreorder(root);
      printf("\n");
      break;
    case 6:
      printf("Iterative In-order Traversal: ");
      iterativeInorder(root);
      printf("\n");
      break;
    case 7:
      printf("Iterative Post-order Traversal: ");
      iterativePostorder(root);
      printf("\n");
      break;
    case 8:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }
}
