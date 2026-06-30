// find the len of min possible subarray whose sum is >=target
#include <bits/stdc++.h>
using namespace std;

int find_len(vector<int> arr, int target)
{
    int sum = 0, l = 0, r = 0;
    int minLen = INT_MAX;
    while (r < arr.size())
    {
        sum += arr[r];
        while (sum >= target)
        {
            minLen = min(minLen, (r - l + 1));
            sum -= arr[l];
            l += 1;
        }
        r += 1;
    }
    return minLen;
}

int main()
{
    vector<int> arr = {1, 4, 4};
    cout << find_len(arr, 4);
    return 0;
}