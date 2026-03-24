#include <iostream>
using namespace std;

class DateTime
{
private:
    int day;
    string month;
    int year;
    float hours, minutes, seconds;

public:
    DateTime()
    {
        day = 0;
        month = "";
        year = 0;
        hours = minutes = seconds = 0;
    }
    void setValue(int d, string m, int y)
    {
        day = d;
        month = "";
        year = y;
        hours = minutes = seconds = 0;
    }
    void setValue(int d, string m, int y, float hr)
    {
        day = d;
        month = "";
        year = y;
        hours = hr;
        minutes = seconds = 0;
    }
    void setValue(int d, string m, int y, float hr, float min)
    {
        day = d;
        month = "";
        year = y;
        hours = hr;
        minutes = min;
        seconds = 0;
    }
    void setValue(int d, string m, int y, float hr, float min, float sec)
    {
        day = d;
        month = "";
        year = y;
        hours = hr;
        minutes = min;
        seconds = sec;
    }
    void Display()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }
};
int main()
{
    DateTime dt;

    dt.setValue(24, "March", 2026);
    dt.Display();

    cout << endl;

    dt.setValue(24, "March", 2026, 10);
    dt.Display();

    cout << endl;

    dt.setValue(24, "March", 2026, 10, 20);
    dt.Display();

    cout << endl;

    dt.setValue(24, "March", 2026, 10, 20, 45);
    dt.Display();

    return 0;
}
