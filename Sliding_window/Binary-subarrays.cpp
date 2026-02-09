#include <bits/stdc++.h>
using namespace std;

int AtMost(vector<int> arr, int goal)
{
    int sum = 0, count = 0, l = 0, r = 0;
    while (r < arr.size())
    {
        sum += arr[r];
        while (sum > goal)
        {
            sum -= arr[l];
            l += 1;
        }
        count += (r - l + 1);
        r += 1;
    }
    return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return AtMost(nums, goal) - AtMost(nums, goal - 1);
}

int main()
{
    vector<int> arr = {1, 0, 1, 0, 1};
    cout << numSubarraysWithSum(arr, 2);
    return 0;
}