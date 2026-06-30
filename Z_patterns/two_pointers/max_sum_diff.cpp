#include <bits/stdc++.h>
using namespace std;

int sum_closest(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int min_diff = INT_MAX;
    int res_sum = 0;
    for (int i = 0; i < arr.size() - 2; i++)
    {
        int l = i + 1, r = arr.size() - 1;
        while (l < r)
        {
            int sum = arr[i] + arr[l] + arr[r];
            int diff = abs(target - sum);
            if (min_diff > diff)
            {
                min_diff = diff;
                res_sum = sum;
            }
            if (sum == target)
                break;
            else if (sum > target)
                r -= 1;
            else
                l += 1;
        }
    }
    return res_sum;
}

int main()
{
    vector<int> arr = {-1, 2, 1, -4};
    cout << sum_closest(arr, 1);
    return 0;
}