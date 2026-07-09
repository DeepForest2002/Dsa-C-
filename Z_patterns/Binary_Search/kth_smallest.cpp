#include <iostream>
#include <vector>
using namespace std;
int smaller_elements(vector<vector<int>> &arr, int mid)
{
    int row = arr.size() - 1;
    int col_size = arr.size();
    int col = 0;
    int ans = 0;
    while (col < col_size && row >= 0)
    {
        int el = arr[row][col];
        if (el > mid)
            row -= 1;
        else
        {
            ans += (row + 1);
            col += 1;
        }
    }
    return ans;
}

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    // if(n*n==k) return matrix[0][0];
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int small = smaller_elements(matrix, mid);
        if (small >= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    return 0;
}