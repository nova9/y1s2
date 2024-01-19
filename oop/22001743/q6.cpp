#include <iostream>
using namespace std;

class Employee
{
private:
  string name;
  int year;
  int salary;
  string address;
  

public:
  Employee(string name,int year,int salary,string address){
    this ->name=name;
    this->year=year;
    this->salary=salary;
    this->address=address;
  }
  void display(){
    cout<<"Name "<<this->name<<endl;
    cout<<"year"<<this->year<<endl;
    cout<<"salary"<<this->salary<<endl;
    cout<<"address"<<this->address<<endl;
  }

};



int main()
{
Employee E1("Robert",1994,400000,"64C- WallsStreat");
Employee E2("Sam",2000,450000,"68D- WallsStreat");
Employee E3("John",1999,67000,"WallsStreat");
E1.display();
E2.display();
E3.display();


  
}