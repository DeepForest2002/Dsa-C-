#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int> arr, int target)
{
    int l = 0, r = arr.size() - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] < target)
        {
            res = arr[mid];
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res;
}

int find_ceil(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            res = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int main()
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    cout << findFloor(arr, 5);
    cout << find_ceil(arr, 5);
    return 0;
}