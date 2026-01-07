#include <iostream>
#include <vector>
using namespace std;

bool check_sum(int index, int sum, int s, vector<int> &ds, vector<int> &arr, int n)
{
    if (index == n)
    {
        if (sum == s)
        {
            for (auto el : ds)
                cout << el << " ";
            cout << endl;
            return true;
        }
        else
            return false;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    if (check_sum(index + 1, sum, s, ds, arr, n) == true)
        return true;
    s -= arr[index];
    ds.pop_back();
    if (check_sum(index + 1, sum, s, ds, arr, n) == true)
        return true;
    return false;
}

int findK(int index, int sum, int s, vector<int> &ds, vector<int> &arr, int n)
{
    if (index == n)
    {
        if (s == sum)
            return 1;
        else
            return 0;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    int l = findK(index + 1, sum, s, ds, arr, n);
    s -= arr[index];
    ds.pop_back();
    int r = findK(index + 1, sum, s, ds, arr, n);
    return l + r;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int sum = 2;
    vector<int> ds;
    int k = 0;
    // cout << check_sum(0, sum, 0, ds, arr, arr.size());
    cout << findK(0, sum, 0, ds, arr, arr.size());
    return 0;
}