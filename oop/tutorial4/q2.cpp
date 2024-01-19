#include <iostream>
using namespace std;

int main()
{
  int number;

  cout << "Enter a number to display its multiplication table up to 10: ";
  cin >> number;

  cout << "Multiplication Table for " << number << ":\n";
  for (int i = 1; i <= 10; ++i)
  {
    cout << number << " * " << i << " = " << number * i << endl;
  }
}
