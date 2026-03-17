#include <bits/stdc++.h>
using namespace std;

int find_peak(vector<int> &arr)
{
    int n = arr.size();
    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];
    int l = 1, r = n - 2;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid] > arr[mid - 1])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    int peak = find_peak(arr);
    cout << peak;
    return 0;
}