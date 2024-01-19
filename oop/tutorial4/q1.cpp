#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter a positive integer n: ";
  cin >> n;


    int sum = 0;

    for (int i = 1; i <= n; ++i)
    {
      sum += i;
    }

    cout << "The sum of the first " << n << " natural numbers is: " << sum << endl;
}
