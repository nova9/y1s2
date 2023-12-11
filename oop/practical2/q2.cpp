#include <iostream>

using namespace std;

int main() {
    int a;

    cout << "Enter the value of 'a': ";
    cin >> a;

    cout << "Result:" << endl;
    cout << "The value of a is: " << a << endl;
    cout << ".........................." << endl;

    cout << "The value of ++a is: " << ++a << " Now the value of a is: " << a << endl;
    cout << ".........................." << endl;

    cout << "The value of a++ is: " << a++ << " Now the value of a is: " << a << endl;
    cout << ".........................." << endl;

    cout << "The value of --a is: " << --a << " Now the value of a is: " << a << endl;
    cout << ".........................." << endl;

    cout << "The value of a-- is: " << a-- << " Now the value of a is: " << a << endl;
    cout << ".........................." << endl;
}
