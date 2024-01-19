#include <iostream>
using namespace std;

class Area
{
private:
  int breadth;
  int length;
  

public:
  void setDim();
  void getArea();
};

void Area::setDim()
{
  
  cout << "Enter the lenght: ";
  cin>> length;
   
  cout<<"Enter the breadth: ";
  cin>>breadth;
  
}

void Area::getArea()
{
  cout << "Area"<<(0.5)*length*breadth;
}

int main()
{
  Area A1;
 
  A1.setDim();
  A1.getArea();

  
}