#include <iostream>

int main()
{
  int sum = 0;
  int number = 0;

  while (true)
  {
    std::cout << "Enter a number (enter 0 or a negative number to stop): ";
    std::cin >> number;

    if (number <= 0)
    {
      break;
    }

    sum += number;
  }

  std::cout << "Sum of positive numbers: " << sum << std::endl;
}
