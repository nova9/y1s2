#include <iostream>

using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE];

    cout << "Enter 5 integer values:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "Values in forward order:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Values in reversed order:" << endl;
    for (int i = SIZE - 1; i >= 0; --i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}
