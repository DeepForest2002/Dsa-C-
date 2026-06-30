#include <iostream>
#include <vector>
using namespace std;

int find_mountain(vector<int> nums)
{
    int low = 0, high = nums.size() - 1;
    int res = 0;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res == 0 ? nums[res] : nums[res + 1];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << find_mountain(arr);
    return 0;
}