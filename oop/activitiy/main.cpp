#include <iostream>
#include "Date.hpp"

using namespace std;

class Temp
{
public:
    int a;

public:
    Temp()
    {
        a = 1;
    }
    
    int increment()
    {
        return ++a;
    }
} t;

int main()
{
    int a = 7;

    cout << t.increment() << endl;
}