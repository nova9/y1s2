#include <iostream>
using namespace std;

class Triangle
{
private:
  int height;
  int length;
  int width;

public:
  Triangle(int h, int l, int w) : height(h), length(l), width(w) {}

  void printArea();
  void printPeremeter();
};

void Triangle::printPeremeter()
{
  cout << height + length + width;
}

void Triangle::printArea()
{
  cout << height * length * width;
}

int main()
{
  Triangle T1(3, 4, 5);

  T1.printPeremeter();
  cout<<endl;
  T1.printArea();
}