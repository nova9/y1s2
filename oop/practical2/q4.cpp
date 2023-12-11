#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 7; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << j;
        }

        for (int j = 7 - i; j > 0; --j)
        {
            cout << "*";
        }

        cout << "\n";
    }
}
