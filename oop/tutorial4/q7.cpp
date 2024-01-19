#include <iostream>

class Int
{
private:
  int data;

public:
  Int(int value = 0): data(value) {}

  Int operator+(const Int& obj) {
    return Int(data + obj.data);
  }

  void operator=(const Int& obj) {
    data = obj.data;
  }

  friend std::ostream& operator<<(std::ostream& out, const Int& obj) {
    out << obj.data;
    return out;
  }
};

int main()
{
  Int a = 2000;

  Int b = 3;

  Int sum;

  sum  = a + b;

  std::cout << sum << std::endl;
}