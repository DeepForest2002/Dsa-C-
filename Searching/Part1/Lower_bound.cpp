// Find the min index where the element is >= to the given element
#include <iostream>
#include <vector>
using namespace std;

int find_lower_bound(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
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
    vector<int> arr = {1, 2, 3, 3, 7, 8, 9, 10, 12, 11};
    int target = 9;
    // int index = find_lower_bound(arr, target);
    // cout << index;
    // cout << ans;
    int index = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    cout << index;
    return 0;
}