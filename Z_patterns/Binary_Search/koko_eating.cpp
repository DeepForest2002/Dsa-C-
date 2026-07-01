#include <bits/stdc++.h>
using namespace std;

int isPossible(const vector<int> &nums, int speed)
{
    int hours = 0;

    for (int bananas : nums)
        hours += ceil((double)bananas / speed);

    return hours;
}

int koko_bananas(const vector<int> &nums, int h)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(nums, mid) <= h)
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
    vector<int> nums = {3, 6, 7, 11};
    cout << koko_bananas(nums, 8);
}