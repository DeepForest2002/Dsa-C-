#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sjf(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int wt = 0, t = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        wt += t;
        t += arr[i];
    }
    return wt / arr.size();
}

int main()
{
    vector<int> arr = {4, 3, 7, 1, 2};
    cout << sjf(arr);
    return 0;
}