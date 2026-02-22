#include <iostream>
#include <cstring>
using namespace std;

class Student
{
protected:
    char *name;
    int roll_num;
    double marks[5];
    float percent;

public:
    Student()
    {
        char temp[80];
        cout << "Enter name: ";
        cin >> temp;

        name = new char[strlen(temp) + 1];
        strcpy(name, temp);

        cout << "Enter roll number: ";
        cin >> roll_num;

        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks for test " << i + 1 << " : ";
            cin >> marks[i];
        }

        percent = 0;
    }

    virtual void calc_percent()   
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        percent = (sum / 500) * 100;
    }

    virtual void display()
    {
        calc_percent();
        cout << "\nName: " << name;
        cout << "\nRoll No: " << roll_num;
        cout << "\nPercentage: " << percent << "%\n";
    }

    virtual ~Student()
    {
        delete[] name;
    }
};

// Science Student Class

class ScienceStudent : public Student
{
    double practical;

public:
    ScienceStudent() : Student()
    {
        cout << "Enter practical marks (out of 150): ";
        cin >> practical;
    }

    void calc_percent() override
    {
        double sum = practical;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        percent = (sum / 650) * 100;
    }

    void display() override
    {
        calc_percent();
        cout << "\n[Science Student]";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << roll_num;
        cout << "\nPractical Marks: " << practical;
        cout << "\nPercentage: " << percent << "%\n";
    }
};

// Art Student Class

class ArtsStudent : public Student
{
    double optional; 

public:
    ArtsStudent() : Student()
    {
        cout << "Enter optional subject marks (out of 100): ";
        cin >> optional;
    }

    void calc_percent() override
    {
        double sum = optional;
        for (int i = 0; i < 5; i++)
            sum += marks[i];

        percent = (sum / 600) * 100;
    }

    void display() override
    {
        calc_percent();
        cout << "\n[Arts Student]";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << roll_num;
        cout << "\nOptional Subject Marks: " << optional;
        cout << "\nPercentage: " << percent << "%\n";
    }
};


int main()
{
    Student *s[2];

    cout << "\nEnter Science Student Details:\n";
    s[0] = new ScienceStudent();

    cout << "\nEnter Arts Student Details:\n";
    s[1] = new ArtsStudent();

    cout << "\nDisplaying Details:\n";

    for (int i = 0; i < 2; i++)
        s[i]->display();   // Dynamic binding

    for (int i = 0; i < 2; i++)
        delete s[i];       // Virtual destructor ensures proper cleanup
}
