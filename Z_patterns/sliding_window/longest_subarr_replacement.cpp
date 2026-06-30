#include <bits/stdc++.h>
using namespace std;

int longest_subarray(vector<int> &arr, int k)
{
    int l = 0, r = 0, maxLen = INT_MIN;
    int zeroCount = 0;
    while (r < arr.size())
    {
        if (arr[r] == 0)
            zeroCount++;
        while (zeroCount > k)
        {
            if (arr[l] == 0)
                zeroCount--;
            l += 1;
        }
        maxLen = max(maxLen, (r - l + 1));
        r += 1;
    }
    return maxLen == INT16_MIN ? 0 : maxLen;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << longest_subarray(arr, 2);
    return 0;
}