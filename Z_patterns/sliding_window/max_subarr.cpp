#include <bits/stdc++.h>
using namespace std;

int max_size_subarr(vector<int> arr, int k)
{
    int sum = 0, r = 0, l = 0;
    int maxi = INT_MIN;
    while (r < arr.size())
    {

        if (r - l + 1 > k)
        {
            sum -= arr[l];
            l += 1;
        }
        sum += arr[r];
        maxi = max(maxi, sum);
        r += 1;
    }
    return maxi;
}

int main()
{
    vector<int> arr = {100, 200, 300, 400};
    cout << max_size_subarr(arr, 2);
    return 0;
}