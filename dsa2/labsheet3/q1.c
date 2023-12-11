#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, *arr, i;
    char *str;

    printf("Enter the size of the integer array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    printf("The array with consecutive integers is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    arr = realloc(arr, n * 2 * sizeof(int));
    for (i = n + 1; i <= 2 * n; i++)
    {
        arr[i] = i;
    }

    printf("\nThe array with consecutive integers is:\n");
    for (i = 0; i < 2 * n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEnter the size of the string: ");
    scanf("%d", &n);

    str = (char *)calloc(n + 1, sizeof(char));

    if (str == NULL)
    {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }

    printf("Enter a string: ");
    scanf(" ");
    fgets(str, n + 1, stdin);

    printf("The entered string is: %s\n", str);

    free(arr);
    free(str);
}
