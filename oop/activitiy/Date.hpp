class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year): day(day), month(month), year(year) {}

    void setDate(int, int, int);
    void getDate();
};