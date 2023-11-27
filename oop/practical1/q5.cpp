#include <iostream>

using namespace std;

int main() {
    float radius;

    cout << "Radius: ";

    cin >> radius;

    cout << "Area: " << 4 * 3.14 * radius * radius << endl;

    cout << "Volume: " << 4 * 3.14 * radius * radius * radius * (1.0/3) << endl;
}