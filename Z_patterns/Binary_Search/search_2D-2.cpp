#include <iostream>
#include <vector>
using namespace std;

bool Binary_search(vector<vector<int>> &arr, int target)
{
    int row = arr.size() - 1;
    int col_size = arr[0].size();
    int col = 0;
    while (row >= 0 && col < col_size)
    {
        int el = arr[row][col];
        if (el == target)
            return true;
        else if (el > target)
            row -= 1;
        else
            col += 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    bool res = Binary_search(arr, 5);
    cout << res << endl;
    return 0;
}