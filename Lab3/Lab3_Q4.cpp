#include <iostream>
using namespace std;

class myclass
{
    int data[2];

public:
    int *p;
    myclass()
    {
        p = data;
    }

    void setData(int a, int b)
    {
        p[0] = a;
        p[1] = b;
    }

    void showData()
    {
        cout << p[0] << " " << p[1] << endl;
    }
};

int main()
{
    myclass *cp;
    cp = new myclass[3];
    int size = 3;

    for (int i = 0; i < size; i++)
    {
        (cp + i)->setData(i + 1, (i + 1) * 10);
    }

    cout << "\n\tContents Of Array: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "\n\tObject " << i + 1 << ": ";
        (cp + i)->showData();
        cout << endl;
    }
    delete[] cp;

    return 0;
}