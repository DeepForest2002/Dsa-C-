#include <bits/stdc++.h>
using namespace std;

int x[4] = {-1, 1, 0, 0}; // representing row
int y[4] = {0, 0, -1, 1}; // representing col

bool validDirection(int row, int col, int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return false;
    return true;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int time = 0;
    int fresh = 0;
    queue<pair<int, int>> q;
    int row = grid.size();
    int col = grid[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({i, j});
                grid[i][j] = 0;
            }
            else if (grid[i][j] == 1)
                fresh += 1;
        }
    }
}
int main()
{
    return 0;
}