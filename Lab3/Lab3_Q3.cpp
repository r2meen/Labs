#include <iostream>
using namespace std;

class IntArray
{
    int size;
    int *arr;

public:

    IntArray()
    { // Default Constructor
        size = 0;
        arr = nullptr;
    }

    IntArray(int s)
    { // Parameterized Constructor
        size = s;
        arr = new int[size];

        cout << "Enter " << size << " elements" << endl;

        for (int i = 0; i < size; i++)
            cin >> arr[i];
    }

    IntArray(const IntArray &obj)
    { // Copy Constructor
        size = obj.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        arr[i] = obj.arr[i];
    }

    int sum()
    {
        int total = 0;
        for (int i = 0; i < size; i++)
            total += arr[i];
        return total;
    }
    ~IntArray()
    { // Destructor
        delete[] arr;
    }
};

int main()
{

    IntArray arr0; // default constructor
    cout << "Default array created..." <<endl;
    cout << "Sum = " << arr0.sum() << endl;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    IntArray arr1(n); // parameterized constructor
    cout << "Sum of array elements: " << arr1.sum() << endl;

    IntArray arr2 = arr1; // copy constructor
    cout << "Sum of copied array elements: " << arr2.sum() << endl;

    return 0;
}
