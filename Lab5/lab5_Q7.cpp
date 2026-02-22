#include <iostream>
using namespace std;

class Product
{
    string name;
    int productid;

public:
    Product(string n, int id) : name(n), productid(id) {}
    void show()
    {
        cout << "Product Name: " << name << "\n";
        cout << "Product ID: " << productid << "\n";
    }
};

class UtilityItems : public Product
{
    float discount;

public:
    UtilityItems(string n, int id, float d) : Product(n, id)
    {
        discount = d;
    }
    void show()
    {
        Product ::show();
        cout << "Discount: Rs " << discount << "\n";
    }
};

class FoodItems : public UtilityItems
{
    string dateofexpiry;

public:
    FoodItems(string n, int id, float d, string exp) : UtilityItems(n, id, d)
    {
        dateofexpiry = exp;
    }
    void show()
    {
        UtilityItems::show();
        cout << "Date Of Expiry:  " << dateofexpiry << "\n";
    }
};

int main()
{
    FoodItems F1("Meat", 1, 20, "12-01-2026");
    F1.show();

    return 0;
}