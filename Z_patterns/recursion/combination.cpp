#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &temp)
{
    for (auto el : temp)
    {
        cout << el;
    }
    cout << endl;
}

void fnc(vector<int> &arr, int n, int idx, vector<int> &temp)
{
    if (idx == n)
    {
        print(temp);
        return;
    }
    // not take
    fnc(arr, n, idx + 1, temp);
    temp.push_back(arr[idx]);
    fnc(arr, n, idx + 1, temp);
    temp.pop_back();
    return;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> temp;
    fnc(arr, 3, 0, temp);
    return 0;
}