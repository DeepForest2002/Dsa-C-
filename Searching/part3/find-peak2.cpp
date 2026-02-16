#include <bits/stdc++.h>
using namespace std;

int find_max_element(vector<vector<int>> arr, int mid, int n)
{
    int maxi = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][mid] > maxi)
        {
            maxi = arr[i][mid];
            index = i;
        }
    }
    return index;
}

vector<int> find_peak(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int l = 0, r = m - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int row_index = find_max_element(arr, mid, n);
        int left = mid - 1 > 0 ? arr[row_index][mid - 1] : -1;
        int right = mid + 1 < m ? arr[row_index][mid + 1] : -1;
        if (arr[row_index][mid] > left && arr[row_index][mid] > left)
        {
            return {row_index, mid};
        }
        if (arr[row_index][mid] > left)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> arr = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    vector<int> arr = find_peak(arr);
    cout << "Hello World";
    for (auto el : arr)
    {
        cout << el << " ";
    }
    return 0;
}