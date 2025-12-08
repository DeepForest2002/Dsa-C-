#include <iostream>
#include <vector>
using namespace std;

int find_first(vector<int> arr, int n, int target)
{
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int find_last(vector<int> arr, int n, int target)
{
    int ans = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int size = arr.size();
    int target = 8;
    int first = find_first(arr, size, target);
    int last = find_last(arr, size, target);
    // cout << first << " " << last;

    cout << (last - first) + 1;
    return 0;
}