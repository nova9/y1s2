#include <iostream>
// #include <string>

using namespace std;

class Student
{
public:
    string name;
    int age;
    int height;
    int weight;

public:
    Student(string name, int age, int height, int weight)
    {
        this->name = name;
        this->age = age;
        this->height = height;
        this->weight = weight;
    }

    void display()
    {
        cout << name << " " << age << " " << height << " " << weight << endl;
    }
};

int main()
{
    Student s("Thathsara", 333, 333, 333);

    s.display();
}