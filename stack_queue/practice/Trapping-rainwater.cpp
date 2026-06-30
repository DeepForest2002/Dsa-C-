#include <bits/stdc++.h>
using namespace std;

int Trapping_rainwater(vector<int> arr)
{
    vector<int> lmax(arr.size(), 0);
    vector<int> rmax(arr.size(), 0);
    lmax[0] = arr[0];
    rmax[arr.size() - 1] = arr[arr.size() - 1];

    for (int i = 1; i < arr.size(); i++)
    {
        lmax[i] = max(lmax[i - 1], arr[i]);
    }
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int res = min(lmax[i], rmax[i]) - arr[i];
        if (res > 0)
            sum += res;
    }
    return sum;
}

int main()
{
    vector<int> arr = {3, 0, 1, 0, 4, 0, 2};
    cout << Trapping_rainwater(arr);
    return 0;
}