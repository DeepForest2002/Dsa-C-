#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list(vector<int> vertices)
{
    int rows = vertices.size();
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 5},
        {2, 6},
        {3, 7},
        {4, 7},
        {5, 6}};
    vector<vector<int>> ad_list(rows);
    for (int i = 0; i < edges.size(); i++)
    {
        pair<int, int> p = edges[i];
        int src = p.first;
        int dest = p.second;
        ad_list[src].push_back(dest);
        ad_list[dest].push_back(src);
    }
    return ad_list;
}

void bfsTraversal(vector<vector<int>> &AdjList, vector<int> &res, vector<int> &visited, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int el = q.front();
        q.pop();
        res.push_back(el);
        for (int i = 0; i < AdjList[el].size(); i++)
        {
            int neighbours = AdjList[el][i];
            if (visited[neighbours] == false)
            {
                q.push(neighbours);
                visited[neighbours] = true;
            }
        }
    }
}

int main()
{
    vector<int> vertices = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> AdjList = adj_list(vertices);
    vector<int> res;
    vector<int> visited(vertices.size(), 0);
    bfsTraversal(AdjList, res, visited, 0);
    for (auto element : res)
    {
        cout << element << " ";
    }

    return 0;
}