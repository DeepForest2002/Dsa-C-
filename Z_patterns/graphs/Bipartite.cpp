#include <bits/stdc++.h>
using namespace std;
bool res = true;
vector<vector<int>> adj_list_maker(vector<int> nodes)
{
    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {2, 3}};
    vector<vector<int>> adj_list(nodes.size());
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

void dfs(vector<vector<int>> &adj_list, vector<int> &colors, int node, int c)
{
    colors[node] = c;
    for (int i = 0; i < adj_list[node].size(); i++)
    {
        int neighbour = adj_list[node][i];
        if (colors[neighbour] != -1 && colors[neighbour] == c)
            res = false;
        else if (colors[neighbour] == -1)
            dfs(adj_list, colors, neighbour, 1 - c);
    }
}

bool bipartite(vector<vector<int>> &adj_list)
{
    vector<int> colors(adj_list.size(), -1);
    int c = 0;
    for (int i = 0; i < adj_list.size(); i++)
    {
        if (colors[i] == -1)
            dfs(adj_list, colors, i, c);
    }
    return res;
}

int main()
{
    vector<int> nodes = {0, 1, 2, 3};
    vector<vector<int>> adj_list = adj_list_maker(nodes);
    cout << bipartite(adj_list) << endl;
    return 0;
}