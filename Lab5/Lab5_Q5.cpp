#include <iostream>
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
        StampCost = 1;   
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
        cout << "\nTotal Cost: $" << TotalCost();
    }

    float TotalCost() override
    {
        return StampCost + RegistrationCost;
    }
};


// Q5: InsuredRegisteredPost //


class InsuredRegisteredPost : public RegisteredPost
{
    float AmtInsured;

public:
    InsuredRegisteredPost()
    {
        AmtInsured = 20;  
    }

    void Read() override
    {
        RegisteredPost::Read();

        cout << "Enter Amount Insured: ";
        cin >> AmtInsured;
    }

    void Print() override
    {
        RegisteredPost::Print();

        cout << "\nAmount Insured: $" << AmtInsured;
        cout << "\nFinal Total Cost: $" << TotalCost() << endl;
    }

    float TotalCost() override
    {
        return StampCost + RegistrationCost + AmtInsured;
    }
};

int main()
{
    InsuredRegisteredPost envelope;

    envelope.Read();
    cout << "\nPost Details..";
    envelope.Print();

    return 0;
}
