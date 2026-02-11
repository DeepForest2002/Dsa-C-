#include <bits/stdc++.h>
using namespace std;

bool CanPossible(vector<int> arr, int pages, int k)
{
    int student_count = 1;
    long long page_count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (page_count + arr[i] > pages)
        {
            student_count += 1;
            page_count = arr[i];
        }
        else
        {
            page_count += arr[i];
        }
    }
    return student_count <= k;
}
int getSum(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

int Book_Allocation(vector<int> arr, int k)
{
    int ans = -1;
    if (k > arr.size())
        return ans;
    int l = *max_element(arr.begin(), arr.end());
    int r = getSum(arr);
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (CanPossible(arr, mid, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    cout << Book_Allocation(arr, 2);
    return 0;
}