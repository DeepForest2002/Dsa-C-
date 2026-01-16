#include <bits/stdc++.h>
using namespace std;

int Traping_rainwater(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);
    lmax[0] = arr[0];
    rmax[n - 1] = arr[n - 1];
    // for loop for lmax
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(lmax[i - 1], arr[i]);
    }
    // for loop for rmax
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int res = min(lmax[i], rmax[i]) - arr[i];
        if (res > 0)
            sum += res;
    }
    return sum;
}

int main()
{
    vector<int> arr = {4, 2, 0, 3, 2, 5};
    int ans = Traping_rainwater(arr);
    cout << ans;
    return 0;
}