#include <iostream>
using namespace std;

class Room
{
private:
  double length;
  double width;
  double height;

public:
  Room(double l, double w, double h) : length(l), width(w), height(h)
  {
  }

  double calculateArea()
  {
    return 2 * (length * width + length * height + width * height);
  }

  double calculateVolume()
  {
    return length * width * height;
  }
};

int main()
{
  Room room1(5.5, 4.2, 3.0);

  double area = room1.calculateArea();
  double volume = room1.calculateVolume();

  cout << "Area of the room: " << area << " square units" << endl;
  cout << "Volume of the room: " << volume << " cubic units" << endl;
}
