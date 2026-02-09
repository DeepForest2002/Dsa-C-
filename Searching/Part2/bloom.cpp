#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int day, int m, int k)
{
    int count = 0;
    int bq = 0;
    for (auto el : arr)
    {
        if (el <= day)
        {
            count += 1;
            if (count == k)
            {
                bq += 1;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    return bq >= m;
}

int check_days(vector<int> &arr, int m, int k)
{
    long long totalFlowes = 1LL * m * k;
    if (totalFlowes > arr.size())
        return -1;

    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());

    for (int i = mini; i <= maxi; i++)
    {
        if (isPossible(arr, i, m, k))
        {
            return i;
        }
    }
    return -1;
}

int check_days2(vector<int> &arr, int m, int k)
{
    long long totalFlowes = 1LL * m * k;
    if (totalFlowes > arr.size())
        return -1;

    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    int ans = -1;

    while (mini <= maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        if (isPossible(arr, mid, m, k))
        {
            ans = mid;
            maxi = mid - 1;
        }
        else
        {
            mini = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 1, 2, 7, 2, 2, 3, 1};
    cout << check_days2(arr, 2, 3);
    return 0;
}