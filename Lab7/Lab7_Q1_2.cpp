#include <iostream>
using namespace std;

const double PI = 3.14159;

class Shape
{

protected:
    double area;

public:
    Shape() : area(0) {}

    virtual void Calculate_Area() = 0;

    virtual void Display()
    {
        cout << "Area : " << area << "cm" << endl;
    }
};

class Circle : public Shape
{

private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void Calculate_Area() override
    {
        if (radius > 0)
        {
            area = PI * radius * radius;
        }
        else
        {
            cout << "Invalid dimensions!" << endl;
            area = 0;
        }
    }

    void Display() override
    {
        cout << "----- CIRCLE ------" << endl;
        cout << "Area Of A Circle: " << area << " cm^2" << endl;
    }
};

class Rectangle : public Shape
{

private:
    double length, breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    void Calculate_Area() override
    {
        if (length && breadth > 0)
        {
            area = length * breadth;
        }
        else
        {
            cout << "Invalid dimensions!" << endl;
            area = 0;
        }
    }

    void Display() override
    {
        cout << "----- RECTANGLE -----" << endl;
        cout << "Length: " << length << " cm" << endl;
        cout << "Breadth: " << breadth << " cm" << endl;
        cout << "Area Of A Rectangle: " << area << " cm^2" << endl;
    }
};

int main()
{
    Circle C(5);
    Rectangle R(4, 6);

    C.Calculate_Area();
    C.Display();

    R.Calculate_Area();
    R.Display();

    return 0;
}
