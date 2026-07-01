#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// search min in sorted rotated arr
int find_mountain(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;
    int res = INT_MAX;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[mid])
        {
            res = min(res, nums[low]);
            low = mid + 1;
        }
        else
        {
            res = min(res, nums[mid]);
            high = mid - 1;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << find_mountain(arr);
    return 0;
}