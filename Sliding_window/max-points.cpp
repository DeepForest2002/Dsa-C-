#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> arr, int k)
{
    int l = 0, r = arr.size() - 1, sum = 0;
    while (k)
    {
        if (arr[l] > arr[r])
        {
            sum += arr[l];
            l += 1;
            k -= 1;
        }
        else if (arr[r] > arr[l])
        {
            sum += arr[r];
            r -= 1;
            k -= 1;
        }
        else
        {
            sum += (arr[l] + arr[r]);
            l += 1;
            r -= 1;
            k -= 2;
        }
    }
    return sum;
}

int main()
{
    vector<int> ans = {1, 79, 80, 1, 1, 1, 200, 1};
    cout << find_max(ans, 3);
    return 0;
}