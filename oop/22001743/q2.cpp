#include<iostream>
using namespace std;

class Student{
  public:
      string name;
      int roll_no;
  


};

int main(){
  Student student1;
  student1.name="John";
  student1.roll_no=2;

  cout<<"name "<<student1.name<<endl;
  cout<<"roll_no  "<<student1.roll_no<<endl;
  
}