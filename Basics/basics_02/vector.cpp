#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Syntax of vector
    vector<int> vc = {1, 4, 5, 89, 10, 12};
    cout << vc.size();

    // Adding element to the vector
    vc.push_back(13);

    // Delet element
    vc.pop_back();

    for (int i = 0; i < vc.size(); i++)
    {
        cout << vc[i] << " ";
    }

    cout << vc.at(1);
    return 0;
}