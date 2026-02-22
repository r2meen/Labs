#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollno;
    float marks;

public:
    void input()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollno;
        cout << "Enter Marks: ";
        cin >> marks;
        cout << endl;
    }

    void display() const
    {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << rollno;
        cout << "\nMarks: " << marks;
        cout << "\n----------------------";
    }

    int getRollNo() const
    {
        return rollno;
    }
};

int main()
{
    Student students[10];
    Student *ptr = students;

    cout << "Enter records of 10 students:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        ptr[i].input();
    }

    cout << "\n\n--- Student Records ---\n";
    for (int i = 0; i < 10; i++)
    {
        ptr[i].display();
    }

    int searchRoll;
    cout << "\n\nEnter Roll Number to search: ";
    cin >> searchRoll;

    bool found = false;
    for (int i = 0; i < 10; i++)
    {
        if (ptr[i].getRollNo() == searchRoll)
        {
            cout << "\nRecord Found:";
            ptr[i].display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nRecord not found.";
    }

    return 0;
}
