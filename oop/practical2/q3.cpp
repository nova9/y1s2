#include <iostream>

#define SIZE 3

using namespace std;

int max(int a, int b)
{
    return a < b ? a : b;
}

int greatest(int *nums, int start, int end, int z)
{
    if(end == start) {
        return nums[end];
    }
    return greatest(nums, start + 1, end, nums[start]);
}

int main()
{
    int nums[SIZE];

    cout << "Enter three integer values:" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        printf("Value %d: ", i + 1);
        cin >> nums[i];
    }

    int max = greatest(nums, 1, SIZE - 1, nums[0]);

    cout << "The greatest value is: " << max << endl;
}
