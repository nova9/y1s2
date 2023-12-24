#include <stdio.h>
#include <stdlib.h>

int *concatArrays(int *firstArray, int sizeFirst, int *secondArray, int sizeSecond)
{
    int *arr = malloc(sizeof(int) * (sizeFirst + sizeSecond));
    for (int i = 0; i < sizeFirst; i++)
    {
        arr[i] = firstArray[i];
    }

    for (int i = 0; i < sizeSecond; i++)
    {
        arr[sizeFirst + i] = secondArray[i];
    }

    return arr;
}

int main()
{
    int sizeFirst;

    printf("Enter the number of elements for the first array: ");
    scanf("%d", &sizeFirst);

    int firstArray[sizeFirst];

    printf("Enter %d elements:\n", sizeFirst);
    for (int i = 0; i < sizeFirst; i++)
    {
        scanf("%d", &firstArray[i]);
    }

    int sizeSecond;

    printf("Enter the number of elements for the first array: ");
    scanf("%d", &sizeSecond);

    int secondArray[sizeSecond];

    printf("Enter %d elements:\n", sizeSecond);
    for (int i = 0; i < sizeSecond; i++)
    {
        scanf("%d", &secondArray[i]);
    }

    int *concat = concatArrays(firstArray, sizeFirst, secondArray, sizeSecond);

    for (int i = 0; i < sizeFirst + sizeSecond; i++)
    {
        printf("%d ", concat[i]);
    }

    free(concat);
}