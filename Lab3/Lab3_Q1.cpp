#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int rollno;
    float marks;

public:
    Student() : name(""), rollno(0), marks(0.0f) {}

    Student(const string n, int r, float m)
    {
        name = n;
        rollno = r;
        marks = m;
    }

    void display() const
    {
        cout << "\n\t----------------------------";
        cout << "\n\t Name: " << name;
        cout << "\n\t Roll Number: " << rollno;
        cout << "\n\t Marks: " << marks;
        cout << "\n\t----------------------------";
    }

    int getrollno() const{
        return rollno;
    }
    void runProgram();
};

void Student ::runProgram()
{
    Student *s[10];
    cout << "\n\t--------- STUDENT RECORD SYSTEM ----------";
    for (int i = 0; i < 10; i++)
    {
        string n;
        int r;
        float m;

        cout << "\n\tEnter Data For Student: " << i + 1 << endl;
        cout << "\n\tEnter Name: ";
        cin >> ws;
        getline(cin, n);
        cout << "\n\tEnter Roll Number: ";
        cin >> r;
        cout << "\n\tEnter Marks: ";
        cin >> m;
        cout << "\n\t-----------------------------------------";

        s[i] = new Student(n, r, m);
    }

    cout << "\n\t----------------------------";
    for (int i = 0; i <= 10; i++)
    {
        s[i]->display();
    }
    for (int i = 0; i <= 10; i++)
    {
        delete s[i];
    }
}

int main()
{
    Student s;
    s.runProgram();
    s.display();

    return 0;
}
