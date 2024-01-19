#include <iostream>

class Employee
{
private:
  double salary;
  int hoursWorkedPerDay;

public:
  void getInfo(double initialSalary, int hoursWorked)
  {
    salary = initialSalary;
    hoursWorkedPerDay = hoursWorked;
  }

  void addSal()
  {
    if (salary < 500.0)
    {
      salary += 10.0;
    }
  }

  void addWork()
  {
    if (hoursWorkedPerDay > 6)
    {
      salary += 5.0;
    }
  }

  void displayFinalSalary() const
  {
    std::cout << "Final Salary: $" << salary << std::endl;
  }
};

int main()
{
  Employee employee;

  double initialSalary;
  int hoursWorked;
  std::cout << "Enter initial salary: $";
  std::cin >> initialSalary;
  std::cout << "Enter hours of work per day: ";
  std::cin >> hoursWorked;

  employee.getInfo(initialSalary, hoursWorked);

  employee.addSal();

  employee.addWork();

  employee.displayFinalSalary();
}
