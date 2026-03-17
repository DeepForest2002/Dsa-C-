#include <bits/stdc++.h>
using namespace std;

int find_missing_number(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(arr[i], maxi);
    }
    int j = 0;
    int i = 1;
    for (; i <= maxi; i++)
    {
        if (i != arr[j])
            break;
        j++;
    }
    return i;
}

int main()
{
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1};
    cout << find_missing_number(arr);
    return 0;
}