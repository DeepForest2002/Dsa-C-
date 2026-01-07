
// This is on subsq not on subarray
#include <iostream>
#include <vector>
using namespace std;

void Subsq(int index, vector<int> &arr, vector<int> &ds, int n)
{
    if (index == n)
    {
        for (auto el : ds)
        {
            cout << el << " ";
        }
        cout << endl;
        return;
    }
    // take the element
    ds.push_back(arr[index]);
    Subsq(index + 1, arr, ds, n);
    // remove the element
    ds.pop_back();
    Subsq(index + 1, arr, ds, n);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ds;
    Subsq(0, arr, ds, 3);
    return 0;
}