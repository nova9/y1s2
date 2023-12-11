#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *numbers, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    numbers = (int *)malloc(n * sizeof(int));


    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    printf("The numbers you entered are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\nThe sum of the entered numbers is: %d\n", sum);

    free(numbers);

    return 0;
}
