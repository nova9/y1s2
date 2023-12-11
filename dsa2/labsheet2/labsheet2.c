#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task Task;
struct Task
{
    int id;
    char description[100];
    bool isComplete;
    Task *next;
};

Task *createTask(int id, char *description)
{
    Task *task = malloc(sizeof(Task));
    task->id = id;
    strcpy(task->description, description);
    task->isComplete = false;
    task->next = NULL;
    return task;
}

Task *addTask(Task *tasks, char *description)
{
    if (tasks == NULL)
    {
        return createTask(1, description);
    }

    Task *ptr = tasks;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = createTask(ptr->id + 1, description);
    return tasks;
}

void markCompleted(Task *tasks, int id)
{
    Task *ptr = tasks;
    while (ptr->id != id)
    {
        ptr = ptr->next;
    }
    ptr->isComplete = true;
}

void displayTasks(Task *tasks)
{
    Task *ptr = tasks;
    while (ptr != NULL) {
        printf("ID: %d, Description: %s, Status: %s\n", ptr->id, ptr->description, ptr->isComplete ? "Completed" : "Incomplete");
        ptr = ptr->next;
    }
}

Task *removeTask(Task *tasks, int id)
{
    if (tasks->id == id)
    {
        Task *temp = tasks->next;
        free(tasks);
        return temp;
    }

    Task *ptr = tasks;
    while (ptr->next->id != id)
    {
        ptr = ptr->next;
    }
    Task *temp = ptr->next;

    ptr->next = ptr->next->next;

    return tasks;
}

int main()
{
    int choice;
    int id;
    char description[100];

    Task *tasks = NULL;

    do
    {
        printf("\nTo-Do List Application\n");
        printf("1. Add Task\n");
        printf("2. Mark Task as Completed\n");
        printf("3. Remove Task\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Task Description: ");
            scanf(" %[^\n]s", description);
            tasks = addTask(tasks, description);
            break;
        case 2:
            printf("Enter Task ID to mark as completed: ");
            scanf("%d", &id);
            markCompleted(tasks, id);
            break;
        case 3:
            printf("Enter Task ID to remove: ");
            scanf("%d", &id);
            tasks = removeTask(tasks, id);
            break;
        case 4:
            displayTasks(tasks);
            break;
        case 5:
            printf("Exiting application...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
}