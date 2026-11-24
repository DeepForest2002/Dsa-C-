#include <bits/stdc++.h>
using namespace std;

int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

int isValid(int row, int col, int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return false;
    return true;
}

int minimumEffortPath(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();
    // res
    vector<vector<int>> res(m, vector<int>(n, INT_MAX));

    // min heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    res[0][0] = 0;
    while (!pq.empty())
    {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int dist = p.first;
        int row = p.second.first;
        int col = p.second.second;
        if (dist > res[row][col])
            continue;
        for (int k = 0; k < 4; k++)
        {
            int r = row + x[k];
            int c = col + y[k];
            if (isValid(m, n, r, c))
            {
                int abs_diff = abs(heights[row][col] - heights[r][c]);
                int max_diff = max(abs_diff, dist);
                if (max_diff < res[r][c])
                {
                    res[r][c] = max_diff;
                    pq.push({max_diff, {r, c}});
                }
            }
        }
    }
    return res[m - 1][n - 1];
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << minimumEffortPath(arr);
    return 0;
}