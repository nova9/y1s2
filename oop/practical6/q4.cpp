#include <iostream>

class Volume
{
private:
  double length;
  double breadth;
  double height;

public:
  Volume(double l, double b, double h) : length(l), breadth(b), height(h) {}

  double calculateVolume() const
  {
    return length * breadth * height;
  }

  void displayBoxDetails() const
  {
    std::cout << "Box Dimensions: " << length << " x " << breadth << " x " << height << std::endl;
    std::cout << "Volume of the Box: " << calculateVolume() << std::endl;
  }
};

int main()
{
  Volume box(5.0, 3.0, 2.0);

  box.displayBoxDetails();
}
