#include <iostream>
#include <vector>
using namespace std;

class Chai
{
public:
    string *tea_name;
    int servings;
    vector<string> ingridients;

    Chai(string name, int serve, vector<string> list)
    {
        tea_name = new string(name);
        servings = serve;
        ingridients = list;
        cout << "Cns has been called" << endl;
    }

    // Copy Constructor
    Chai(const Chai &other)
    {
        tea_name = new string(*other.tea_name);
        servings = other.servings;
        ingridients = other.ingridients;
        cout << "Copy Constructor has been called" << endl;
    }

    ~Chai()
    {
        delete tea_name;
        cout << "Destructor has been called" << endl;
    }

    void display()
    {
        cout << "Tea_name is " << *tea_name << endl;
        cout << "servings number is " << servings << endl;
        for (auto ingridient : ingridients)
        {
            cout << ingridient << " ";
        }
        cout << endl;
    }
};

int main()
{

    Chai chai("Lemon Tea", 2, {"Lemon", "Water", "Honey", "Tea_leaf"});
    chai.display();

    // Copy the object once more
    Chai new_obj = chai;
    cout << "Copied Object" << endl;
    new_obj.display();
    return 0;
}