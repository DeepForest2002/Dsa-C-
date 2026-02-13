#include <bits/stdc++.h>
using namespace std;

bool BS(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

bool Binary_search_2d(vector<vector<int>> matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] <= target && target <= matrix[i][col - 1])
        {
            return BS(matrix[i], target);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << Binary_search_2d(matrix, 18);
    return 0;
}