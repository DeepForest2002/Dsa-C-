#include <iostream>
#include <vector>
using namespace std;

class Chai
{
public:
    // Default constructor
    Chai()
    {
        cout << "Constructor Called" << endl;
    }
};

int main()
{
    Chai chai;
    return 0;
}