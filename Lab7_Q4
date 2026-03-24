
#include <iostream>
using namespace std;

class abc { 
public: 
    virtual void func() = 0; 
}; 

class xyz : public abc { 
public: 
    void func() override { 
        cout << "this is function of xyz" << endl;
    } 
}; 

int main() { 
 // abc obj1; 
 // cannot instantiate abstract class therefore correct version can be written by using pointer to abstract class 

    abc* obj1 = new xyz();
    abc* obj2 = new xyz();

    obj1 -> func();
    obj2 -> func(); 

    delete obj1; 
    delete obj2; 

    return 0; 
}
