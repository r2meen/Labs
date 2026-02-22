#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    char *name;
    int roll_num;
    double marks[5];
    float percent;

public:
    Student()
    {
        char temp[80];
        cout << "Enter name: " << endl;
        cin >> temp;

        name = new char[strlen(temp) + 1];   // FIXED
        strcpy(name, temp);

        cout << "Enter roll number: " << endl;
        cin >> roll_num;

        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks for test no." << i + 1 << " : " << endl;
            cin >> marks[i];
        }
        percent = 0;
    }

    Student(char *s, int r)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
        roll_num = r;

        for (int i = 0; i < 5; i++)
        {
            cout << "Enter marks for test no." << i + 1 << " : " << endl;
            cin >> marks[i];
        }
        percent = 0;
    }

    Student(Student &s)
    {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        roll_num = s.roll_num;

        for (int i = 0; i < 5; i++)
        {
            marks[i] = s.marks[i];
        }
        percent = s.percent;
    }

    ~Student()
    {
        delete[] name;
    }

    char *get_name()
    {
        return name;
    }

    int get_rollnum()
    {
        return roll_num;
    }

    double get_marks(int i)
    {
        return marks[i - 1];
    }

    // 🔹 NEW FUNCTION ADDED
    double highest_mark()
    {
        double max = marks[0];
        for (int i = 1; i < 5; i++)
        {
            if (marks[i] > max)
            {
                max = marks[i];
            }
        }
        return max;
    }

    void set_name(char *s)
    {
        delete[] name;
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void set_roll(int r)
    {
        roll_num = r;
    }

    void set_marks(int n)
    {
        double num;
        cout << "Enter new marks for test " << n << " : ";
        cin >> num;
        marks[n - 1] = num;
    }

    void calc_percent();
    void grade();
    void display();
};

void Student::calc_percent()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }
    percent = (sum / 500) * 100;
}

void Student::grade()
{
    calc_percent();
    cout << "Percentage: " << percent << "%\n";

    if (percent >= 80)
        cout << "Grade: A\n";
    else if (percent >= 60)
        cout << "Grade: B\n";
    else if (percent >= 50)
        cout << "Grade: C\n";
    else
        cout << "Grade: F\n";
}

void Student::display()
{
    cout << "\nName: " << name;
    cout << "\nRoll No: " << roll_num << endl;
    grade();
}

int main()
{
    Student *s;
    s = new Student[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "\nStudent " << i + 1 << " Details:\n";
        s[i].display();
    }

    // Display highest marks of both students
    for (int i = 0; i < 2; i++)
    {
        cout << "\nHighest mark of Student " << i + 1 << " : "
             << s[i].highest_mark() << endl;
    }

    delete[] s;
}
