#include <bits/stdc++.h>
using namespace std;

void merge_arr(vector<int> &arr, int low, int mid, int high)
{
    int left = low, right = mid + 1;
    vector<int> ans;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            ans.push_back(arr[left]);
            left += 1;
        }
        else
        {
            ans.push_back(arr[right]);
            right += 1;
        }
    }
    while (left <= mid)
    {
        ans.push_back(arr[left]);
        left += 1;
    }
    while (right <= high)
    {
        ans.push_back(arr[right]);
        right += 1;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        arr[low + i] = ans[i];
    }
    return;
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge_arr(arr, low, mid, high);
}
int main()
{
    vector<int> arr = {4, 2, 7, 1, 5, 3};
    merge_sort(arr, 0, arr.size() - 1);
    for (auto el : arr)
    {
        cout << el << " ";
    }
    return 0;
}