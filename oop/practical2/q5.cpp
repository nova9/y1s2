#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    const int size = 10;
    int numbers[size];

    cout << "Enter 10 integer values:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "Value " << i + 1 << ": ";
        cin >> numbers[i];
    }

    bubbleSort(numbers, size);

    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size / 2; ++i)
    {
        int temp = numbers[i];
        numbers[i] = numbers[size - i - 1];
        numbers[size - i - 1] = temp;
    }

    cout << "Sorted array in descending order:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}
