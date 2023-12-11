#include <iostream>

using namespace std;

void reverseArray(int *arr, int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main()
{
    int Array[] = {4, 2, 7, 5, 8, 1, 6};
    int size = sizeof(Array) / sizeof(Array[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << Array[i] << " ";
    }
    cout << endl;

    reverseArray(Array, size);

    cout << "Reversed Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}
