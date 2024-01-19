#include <iostream>

int main()
{
  int sum_positive = 0;
  int number;

  do
  {
    std::cout << "Enter a number (enter 0 or a negative number to stop): ";
    std::cin >> number;

    if (number > 0)
    {
      sum_positive += number;
    }

  } while (number > 0);

  std::cout << "Sum of positive numbers: " << sum_positive << std::endl;
}
