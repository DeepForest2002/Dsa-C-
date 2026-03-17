#include <bits/stdc++.h>
using namespace std;
int first(vector<int> arr, int target)
{
    int f = -1;
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            f = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return f;
}
int last(vector<int> arr, int target)
{
    int f = -1;
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            f = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return f;
}
int main()
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    pair<int, int> ans;
    ans.first = first(arr, 13);
    ans.second = last(arr, 13);
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}