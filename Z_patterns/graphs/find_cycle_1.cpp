#include <bits/stdc++.h>
using namespace std;

bool cycle = false;

vector<vector<int>> adj_list_maker(vector<int> nodes)
{
    int n = nodes.size();
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    vector<vector<int>> adj_list(n);

    for (int i = 0; i < edges.size(); i++)
    {
        pair<int, int> p = edges[i];
        int src = p.first;
        int dest = p.second;
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }
    return adj_list;
}

void dfs(vector<vector<int>> &adj_list, vector<int> &visited, int node, int parent)
{
    // mark the current node as visited
    visited[node] = 1;
    for (int i = 0; i < adj_list[node].size(); i++)
    {
        int neighbour = adj_list[node][i];
        if (visited[neighbour] == 1 && parent != neighbour)
            cycle = true;
        else if (visited[neighbour] == 0)
        {
            dfs(adj_list, visited, neighbour, node);
        }
    }
}

void findCycle(vector<vector<int>> &adj_list)
{
    if (adj_list.size() <= 2)
    {
        return;
    }
    vector<int> visited(adj_list.size(), 0);
    for (int i = 0; i < adj_list.size(); i++)
    {
        if (visited[i] == 0)
        {
            dfs(adj_list, visited, i, -1);
        }
    }
}

int main()
{
    vector<int> nodes = {0, 1, 2, 3};
    vector<vector<int>> adj_list = adj_list_maker(nodes);
    findCycle(adj_list);
    cout << cycle << endl;
    return 0;
}