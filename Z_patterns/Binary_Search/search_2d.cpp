#include <iostream>
#include <vector>
using namespace std;

// first way to search

bool binary_search(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

bool search2D(vector<vector<int>> &arr, int target)
{
    int row = arr.size();
    int low = 0, high = row - 1;
    int ans_row = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid][0] <= target)
        {
            ans_row = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (ans_row == -1)
        return false;
    bool ans = binary_search(arr[ans_row], target);
    return ans;
}

// second way in one go
bool binary_search2(vector<vector<int>> &arr, int target)
{
    int row = arr.size();
    int col = arr[0].size();
    int low = 0, high = (row * col) - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // to get the row we have to divide the mid with col
        // to get the col we have to perform modulus of index with col
        if (arr[mid / col][mid % col] == target)
            return true;
        else if (arr[mid / col][mid % col] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7, 10}, {11, 13, 15, 20, 21}, {23, 27, 30, 33, 35}, {40, 43, 50, 52, 60}};
    cout << search2D(arr, 42) << endl;
    ;
    cout << binary_search2(arr, 43);
    return 0;
}