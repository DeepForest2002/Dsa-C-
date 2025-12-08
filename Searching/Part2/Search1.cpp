#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum_elements(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

bool possible(vector<int> &arr, int mid, int days)
{
    int days_count = 1; // start with day 1
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (sum + arr[i] > mid)
        {
            days_count += 1;
            sum = arr[i];
            if (days_count > days)
                return false;
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int shipWithinDays(vector<int> &arr, int days)
{
    // int low = *max_element(arr.begin(), arr.end());
    int low = 1;
    int high = sum_elements(arr);
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(arr, mid, days))
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(arr, days);
    return 0;
}