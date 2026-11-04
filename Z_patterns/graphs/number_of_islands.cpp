#include <bits/stdc++.h>
using namespace std;

/*int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

bool isValid(int row, int col, int r, int c)
{
    if (row < 0 || row >= r || col < 0 || col >= c)
        return false;

    return true;
}

void dfs(vector<vector<char>> &grid,
         int r,
         int c,
         int i,
         int j,
         vector<vector<int>> &visited)
{
    visited[i][j] = 1;

    // 4 directions: up, down, left, right
    for (int k = 0; k < 4; k++)
    {
        int row = i + x[k];
        int col = j + y[k];

        if (isValid(row, col, r, c) &&
            visited[row][col] == 0 &&
            grid[row][col] == '1')
        {
            dfs(grid, r, c, row, col, visited);
        }
    }
}

int findCircleNum(vector<vector<char>> &grid)
{
    int row_size = grid.size();
    int col_size = grid[0].size();

    vector<vector<int>> visited(
        row_size,
        vector<int>(col_size, 0));

    int res = 0;

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            if (visited[i][j] == 0 && grid[i][j] == '1')
            {
                dfs(grid, row_size, col_size, i, j, visited);
                res++;
            }
        }
    }

    return res;
}
*/

int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, +1};

bool isValid(int row, int col, int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return false;
    return true;
}

void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col, int i, int j)
{
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int r = i + x[k];
        int c = j + y[k];
        if (isValid(row, col, r, c) && visited[r][c] == 0 && grid[r][c] == '1')
        {
            dfs(grid, visited, row, col, r, c);
        }
    }
    return;
}

int findCircleNum(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    int res = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1' && visited[i][j] == 0)
            {
                dfs(grid, visited, row, col, i, j);
                res += 1;
            }
        }
    }
}

// total time complexity is 0(n^2) and space complexity 0(n^2) visited array

int main()
{
    return 0;
}