#include <stdio.h>
#include <stdlib.h>

int findMaxElement(void *arr, int arr_length)
{
    int *ptr = (int *)arr;
    int max = ptr[0];

    for (int i = 1; i < arr_length; i++)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
        }
    }

    return max;
}

int main()
{
    int input;
    int *arr = malloc(sizeof(int));
    int arr_length = 0;

    do
    {
        scanf("%d", &input);
        arr = realloc(arr, sizeof(int));
        arr[arr_length] = input;
        arr_length += 1;

    } while (input != -1);

    for (int i = arr_length - 1; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }

    printf("Max element = %d\n", findMaxElement((void *)arr, arr_length));

    free(arr);
}
