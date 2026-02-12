#include <bits/stdc++.h>
using namespace std;

int find_p(vector<int> arr, int mid)
{
    int count = 1;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] <= mid)
        {
            sum += arr[i];
        }
        else
        {
            sum = arr[i];
            count += 1;
        }
    }
    return count;
}

int painters_partition(vector<int> arr, int k)
{
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    if (k > arr.size())
        return ans;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        int p = find_p(arr, m);
        if (p <= k)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    cout << painters_partition(arr, 2);
    return 0;
}