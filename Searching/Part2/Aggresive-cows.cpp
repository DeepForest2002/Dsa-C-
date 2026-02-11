#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool CanPossible(vector<int> arr, int dist, int k)
{
    int count = 1;
    int lastpos = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - lastpos >= dist)
        {
            count += 1;
            lastpos = arr[i];
        }
    }
    return count >= k;
}

int check_max_dist(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr.end() - arr.begin();
    int ans = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (CanPossible(arr, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int aggresive_cows(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr.end() - arr.begin();
    int ans = 1;
    for (int i = low; i <= high; i++)
    {
        if (CanPossible(arr, i, k))
        {
            ans = i;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    cout << aggresive_cows(arr, 4);
    return 0;
}