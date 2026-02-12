#include <bits/stdc++.h>
using namespace std;

int AtMost(vector<int> arr, int k)
{
    int l = 0, r = 0, count = 0;
    unordered_map<int, int> mpp;
    while (r < arr.size())
    {
        mpp[arr[r]]++;
        while (mpp.size() > k)
        {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0)
                mpp.erase(arr[l]);
            l += 1;
        }
        if (mpp.size() <= k)
        {
            count += (r - l + 1);
        }
        r += 1;
    }
    return count;
}

int find_subarray(vector<int> nums, int k)
{
    return AtMost(nums, k) - AtMost(nums, k - 1);
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 3};
    cout << find_subarray(arr, 2);
    return 0;
}