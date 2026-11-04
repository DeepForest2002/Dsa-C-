/*
 *Finding cycle in an directed graph
 */
#include <bits/stdc++.h>
using namespace std;

bool cycle = false;

vector<vector<int>> adj_list_maker(vector<int> nodes)
{
    int n = nodes.size();
    vector<pair<int, int>> edges = {{0, 2}, {0, 1}, {1, 3}, {3, 2}};
    vector<vector<int>> adj_list(n);

    for (int i = 0; i < edges.size(); i++)
    {
        pair<int, int> p = edges[i];
        int src = p.first;
        int dest = p.second;
        adj_list[src].push_back(dest);
    }
    return adj_list;
}

void dfs(vector<vector<int>> &adj_list, vector<int> &visited, vector<int> &path, int node)
{
    visited[node] = 1;
    path[node] = 1;
    for (int i = 0; i < adj_list[node].size(); i++)
    {
        int neighbour = adj_list[node][i];
        if (visited[neighbour] == 1 && path[neighbour] == 1)
            cycle = true;
        else if (visited[neighbour] == 0)
            dfs(adj_list, visited, path, neighbour);
    }
    path[node] = 0;
    return;
}

bool find_cycle(vector<vector<int>> &adj_list)
{
    vector<int> visited(adj_list.size(), 0);
    vector<int> path(adj_list.size(), 0);
    for (int i = 0; i < adj_list.size(); i++)
    {
        if (visited[i] == 0)
        {
            dfs(adj_list, visited, path, i);
        }
    }
    return cycle;
}

int main()
{
    vector<int> nodes = {0, 1, 2, 3};
    vector<vector<int>> adj_list = adj_list_maker(nodes);
    // cout << find_cycle(adj_list) << endl;
    int count = 0;
    for (auto one_d_array : adj_list)
    {
        cout << count++ << "->";
        for (auto element : one_d_array)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << find_cycle(adj_list);
    return 0;
}