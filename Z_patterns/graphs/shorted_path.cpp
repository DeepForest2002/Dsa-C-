#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &adj, int src, int dest)
{
    // make a res and visited arr
    if (src == dest)
        return 0;
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> res(n, -1);
    queue<pair<int, int>> q;
    visited[src] = 1;
    res[src] = 0;
    q.push({src, 0});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int dist = p.second;
        res[node] = dist;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i];
            if (visited[neighbour] == 0)
            {
                q.push({neighbour, dist + 1});
                visited[neighbour] = 1;
            }
        }
    }
    return res[dest];
}

int main()
{
    return 0;
}
