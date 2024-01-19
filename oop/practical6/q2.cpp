#include <iostream>

class Complex
{
private:
  float real;
  float imag;

public:
  Complex(float r = 0, float i = 0) : real(r), imag(i) {}

  Complex operator+(const Complex &obj)
  {
    float r = real + obj.real;
    float i = imag + obj.imag;
    return Complex(r, i);
  }

  Complex operator-(const Complex &obj)
  {
    float r = real - obj.real;
    float i = imag - obj.imag;
    return Complex(r, i);
  }

  Complex operator*(const Complex &obj)
  {
    float r = (real * obj.real) - (imag * obj.imag);
    float i = (real * obj.imag) + (imag * obj.real);
    return Complex(r, i);
  }

  friend std::ostream &operator<<(std::ostream &out, const Complex &obj)
  {
    out << "Result: " << obj.real << " + " << obj.imag << "i" << std::endl;
    return out;
  }
};

int main()
{
  Complex complex1(1, 2);
  Complex complex2(1, 4);

  std::cout << "Sum: ";
  std::cout << complex1 + complex2;

  std::cout << "Difference: ";
  std::cout << complex1 - complex2;

  std::cout << "Product: ";
  std::cout << complex1 * complex2;
}
