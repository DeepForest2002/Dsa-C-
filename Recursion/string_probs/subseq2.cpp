#include <iostream>
#include <vector>
using namespace std;

void Printf(int index, int s, int sum, vector<int> &ds, vector<int> arr, int n)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto el : ds)
            {
                cout << el << " ";
            }
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    Printf(index + 1, s, sum, ds, arr, n);
    s -= arr[index];
    ds.pop_back();
    Printf(index + 1, s, sum, ds, arr, n);
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> ds;
    int sum = 2;
    Printf(0, 0, sum, ds, arr, arr.size());
    return 0;
}