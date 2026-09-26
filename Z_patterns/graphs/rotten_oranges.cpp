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
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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

    while (!q.empty() && fresh)
    {
        int size = q.size();
        time += 1;
        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            // 4 directions
            for (int k = 0; k < 4; k++)
            {
                int row = r + x[k];
                int col = c + y[k];
                if (validDirection(n, m, row, col) && grid[row][col] == 1)
                {
                    fresh -= 1;
                    q.push({row, col});
                    grid[row][col] = 0;
                }
            }
        }
    }
    if (fresh)
        return -1;
    return time;
}
int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int ans = orangesRotting(grid);
    cout << ans;

    return 0;
}