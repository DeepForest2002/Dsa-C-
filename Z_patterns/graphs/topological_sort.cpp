/*
 *Topological sort
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list_maker(vector<int> &nodes, vector<int> &indegree)
{

    int rows = nodes.size();
    vector<pair<int, int>> edges = {{5, 0}, {5, 2}, {4, 0}, {2, 3}, {1, 3}, {4, 1}};
    vector<vector<int>> ad_list(rows);
    for (int i = 0; i < edges.size(); i++)
    {
        pair<int, int> p = edges[i];
        int src = p.first;
        int dest = p.second;
        ad_list[src].push_back(dest);
        indegree[dest]++;
    }
    return ad_list;
}

vector<int> topoSort(vector<vector<int>> &adj_list, vector<int> &indegree)
{
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (int i = 0; i < adj_list[node].size(); i++)
        {
            int neigh = adj_list[node][i];
            indegree[neigh] -= 1;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }
    return res;
}

int main()
{
    vector<int> nodes = {0, 1, 2, 3, 4, 5};
    vector<int> indegree(nodes.size(), 0);
    vector<vector<int>> adj_list = adj_list_maker(nodes, indegree);
    vector<int> res = topoSort(adj_list, indegree);
    for (auto el : res)
    {
        cout << el << " ";
    }
    return 0;
}