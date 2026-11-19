#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> make_adj_list(vector<int> nodes)
{
    int n = nodes.size();
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 10}, {1, 3, 4}, {1, 2, 3}, {2, 4, 1}, {2, 3, 4}};
    vector<vector<pair<int, int>>> adj_list(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int src = edges[i][0];
        int dest = edges[i][1];
        int weight = edges[i][2];

        adj_list[src].push_back({dest, weight});
        adj_list[dest].push_back({src, weight});
    }
    return adj_list;
}

vector<int> find_distance(vector<vector<pair<int, int>>> adj_list, int src)
{
    // make them infinity
    vector<int> distance(adj_list.size(), INT_MAX);
    // make a min heap of pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // pushing the src
    distance[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        int dist = p.first;
        int node = p.second;
        pq.pop();
        if (dist > distance[node])
            continue;
        for (int i = 0; i < adj_list[node].size(); i++)
        {
            pair<int, int> list_pair = adj_list[node][i];
            int neighbour = list_pair.first;
            int weight = list_pair.second;
            if (dist + weight < distance[neighbour])
            {
                distance[neighbour] = dist + weight;
                pq.push({dist + weight, neighbour});
            }
        }
    }
    return distance;
}

int main()
{
    vector<int> nodes = {0, 1, 2, 3, 4};
    vector<vector<pair<int, int>>> adj_list = make_adj_list(nodes);
    vector<int> distance = find_distance(adj_list, 0);
    for (auto element : distance)
    {
        cout << element << " ";
    }
    return 0;
}