#include <bits/stdc++.h>
using namespace std;

/*vector<vector<int>> adj_list(vector<int> vertices)
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

void dfsTraversal(vector<vector<int>> &AdjList, vector<int> &res, vector<int> &visited, int node)
{
    res.push_back(node);
    visited[node] = true;
    for (int i = 0; i < AdjList[node].size(); i++)
    {
        int neighbour = AdjList[node][i];
        if (visited[neighbour] == false)
            dfsTraversal(AdjList, res, visited, neighbour);
    }
    return;
}*/

vector<vector<int>> adj_list(vector<int> vertices)
{
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
    int rows = vertices.size();
    vector<vector<int>> ad_list(rows);
    for (int i = 0; i < edges.size(); i++)
    {
        pair<int, int> p = edges[i];
        int src = p.first;
        int dest = p.second;
        ad_list[src].push_back(dest);
        ad_list[dest].push_back(src);
    }
    cout << "end adjlist" << endl;
    return ad_list;
}

void dfsTraversal(vector<vector<int>> &adj_list, vector<int> &res, vector<int> &visited, int node)
{
    res.push_back(node);
    visited[node] = 1;
    for (int i = 0; i < adj_list[node].size(); i++)
    {
        int neighbour = adj_list[node][i];
        if (visited[neighbour] == 0)
        {
            dfsTraversal(adj_list, res, visited, neighbour);
        }
    }
    cout << "End dfs" << endl;
}

int main()
{
    vector<int> vertices = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> AdjList = adj_list(vertices);
    vector<int> res;
    vector<int> visited(vertices.size(), 0);
    dfsTraversal(AdjList, res, visited, 0);
    for (auto element : res)
    {
        cout << element << " ";
    }

    return 0;
}