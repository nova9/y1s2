#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(int *arr, int *size) {
    int index = 0;
    for (int i = 0; i < *size; i++) {
        int j;
        for (j = 0; j < index; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (j == index) {
            arr[index++] = arr[i];
        }
    }                                                          
    *size = index;
}

int main() {
    int n;
    printf("Enter the number of integers to input: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    removeDuplicates(arr, &n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
