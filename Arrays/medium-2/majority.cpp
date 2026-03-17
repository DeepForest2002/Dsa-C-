#include <bits/stdc++.h>
using namespace std;

int count_majority(vector<int> arr)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    int maxi = INT_MIN;
    int element;
    for (auto el : mpp)
    {
        if (el.second > maxi)
        {
            maxi = el.second;
            element = el.first;
        }
    }
    if (maxi > arr.size() / 2)
        return element;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << count_majority(arr);
    return 0;
}