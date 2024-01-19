#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
  string brand;
  string model;
  int year;

public:
  Car(string b, string m, int y)
  {
    brand = b;
    model = m;
    year = y;
  }

  void displayDetails()
  {
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
  }
};

int main()
{
  Car myCar("Toyota", "Corolla", 2022);

  cout << "Car Details:\n";
  myCar.displayDetails();
}
