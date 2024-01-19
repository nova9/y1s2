#include <iostream>
using namespace std;

class Shape
{
protected:
  float width, height;

public:
  Shape(float a, float b)
  {
    width = a;
    height = b;
  }

  double calculateAreaTri()
  {
    return 1.0 / 2 * width * height;
  }

  double calculateAreaRec()
  {
    return width * height;
  }
};

int main()
{
  Shape shape1(5, 7);
  double areaTri = shape1.calculateAreaTri();
  double areaRec = shape1.calculateAreaRec();

  cout << "Area of a Triangle =  " << areaTri << endl;
  cout << "Area of a Rectangle=  " << areaRec << endl;
}
