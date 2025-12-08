#include <iostream>
#include <vector>
using namespace std;

class Chai
{
private:
    string tea_name;
    int servings;

public:
    Chai(string name, int serve)
    {
        tea_name = name;
        servings = serve;
    }

    void display() const
    {
        cout << "Tea name is " << tea_name << " and servings is " << servings << endl;
    }

    // Create a friend function here
    friend bool Compare_servings(const Chai &c1, const Chai &c2);
};

bool Compare_servings(const Chai &c1, const Chai &c2)
{
    return c1.servings > c2.servings;
}

int main()
{
    Chai tea1("Lemon Tea", 5);
    Chai tea2("Ginger Tea", 6);

    if (Compare_servings(tea1, tea2))
    {
        cout << "Lemon tea has more servings" << endl;
    }
    else
    {
        cout << "Ginger tea has more servings" << endl;
    }
    return 0;
}