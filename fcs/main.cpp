#include <iostream>
#include <vector>

using namespace std;

vector<int> slicing(vector<int> &arr, int X, int Y)
{

    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    vector<int> result(Y - X + 1);

    copy(start, end, result.begin());

    return result;
}

int max(int a, vector<int> array)
{
    if (array.size() == 1) {
        return array[0];
    }
    if (a > max(array[0], slicing(array, 1, array.size())))
    {
        return a;
    }
    else
    {
        max(array[0], slicing(array, 1, array.size()));
    }
}

int main()
{
    vector<int> temp;

    temp.push_back(3);
    temp.push_back(36);
    temp.push_back(2);
    temp.push_back(1);

    int result = max(4, temp);

    cout << result << endl;
}