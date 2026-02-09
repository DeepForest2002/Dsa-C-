#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int mid, int thresold)
{
    int count = 0;
    for (auto el : arr)
    {
        count += ceil((double)el / (double)mid);
    }
    return count <= thresold;
}

int find_divisor(vector<int> arr, int thresold)
{
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, mid, thresold))
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
    vector<int> arr = {1, 2, 5, 9};
    cout << find_divisor(arr, 6);
    return 0;
}