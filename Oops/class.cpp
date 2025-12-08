#include <iostream>
#include <vector>
#include <string> // Use this in C++, not <string.h>

using namespace std;

class Chai
{
public:
    // Data members or attributes
    string tea_name = "Milk tea";
    int servings = 3;

    vector<string> ingredients = {"Water", "Milk", "Sugar", "Tea leaves"}; // List of ingredients

    // Member function
    void display_chai_details()
    {
        cout << "Tea name: " << tea_name << endl;
        cout << "Servings: " << servings << endl;
        cout << "Ingredients: ";
        for (string ingredient : ingredients)
        {
            cout << ingredient << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Creating an instance of the class
    Chai obj;
    obj.display_chai_details();

    return 0;
}
