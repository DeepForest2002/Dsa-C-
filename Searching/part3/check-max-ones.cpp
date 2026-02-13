#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
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

int check_index_maxOnes(vector<vector<int>> matrix, int m, int n)
{
    int count_max = INT_MIN;
    int index = -1;
    for (int i = 0; i < m; i++)
    {
        int cnt_ones = n - lowerBound(matrix[i], n, 1);
        if (cnt_ones > count_max)
        {
            count_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1},
                                  {0, 0, 1},
                                  {0, 0, 0}};
    cout << check_index_maxOnes(matrix, 3, 3);
    return 0;
}