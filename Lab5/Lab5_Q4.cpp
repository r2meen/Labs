#include <iostream>
#include <cstring>
using namespace std;

class Post
{
protected:
    string Name;
    string To;
    float StampCost;

public:
    Post()
    {
        StampCost = 1.0;
        To = "";
    }

    virtual void Read()
    {
        cout << "Enter Sender Name: ";
        cin >> Name;

        cout << "Enter Receiver Address: ";
        cin >> To;

        cout << "Enter Stamp Cost: ";
        cin >> StampCost;
    }

    virtual void Print()
    {
        cout << "\nSender Name: " << Name;
        cout << "\nReceiver Address: " << To;
        cout << "\nStamp Cost: $" << StampCost;
    }

    virtual float TotalCost()
    {
        return StampCost;
    }

    virtual ~Post() {}
};

class RegisteredPost : public Post
{
protected:
    float Weight;
    float RegistrationCost;

public:
    RegisteredPost()
    {
        Weight = 20;          
        RegistrationCost = 10; 
    }

    void Read() override
    {
        Post::Read();

        cout << "Enter Weight (grams): ";
        cin >> Weight;

        cout << "Enter Registration Cost: ";
        cin >> RegistrationCost;
    }

    void Print() override
    {
        Post::Print();

        cout << "\nWeight: " << Weight << " gms";
        cout << "\nRegistration Cost: $" << RegistrationCost;
        cout << "\nTotal Cost: $" << TotalCost() << endl;
    }

    float TotalCost() override
    {
        return StampCost + RegistrationCost;
    }
};

int main()
{
    RegisteredPost envelope;

    envelope.Read();

    cout << "\nPost Details..";
    envelope.Print();

    return 0;
}
