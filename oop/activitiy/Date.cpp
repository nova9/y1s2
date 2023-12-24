#include <iostream>
#include "Date.hpp"

void Date::setDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::getDate()
{
    std::cout << day << " " << month << " " << year << std::endl;
}