#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> arr, int k, int mid)
{
    int cows = 1;
    int prevPos = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - prevPos >= mid)
        {
            prevPos = arr[i];
            cows += 1;
        }
    }
    return cows >= k;
}

int aggresive_cows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[arr.size() - 1] - arr[0];
    int res = -1;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, k, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 4, 8, 9};
    cout << aggresive_cows(arr, 3);
    return 0;
}