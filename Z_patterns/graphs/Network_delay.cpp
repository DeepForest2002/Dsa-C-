#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj_list_maker(vector<vector<int>> &times, int n)
{
    vector<vector<pair<int, int>>> adj_list(n);
    for (int i = 0; i < times.size(); i++)
    {
        int src = times[i][0];
        int dest = times[i][1];
        int weight = times[i][2];

        adj_list[src - 1].push_back({dest - 1, weight});
    }
    return adj_list;
}

vector<int> dijkastra(vector<vector<pair<int, int>>> adj_list, int n, int src)
{
    // min heap and distance vector
    vector<int> distance(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // push the first to the queue
    pq.push({0, src - 1});
    distance[src - 1] = 0;
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
            pair<int, int> p = adj_list[node][i];
            int neighbour = p.first;
            int wt = p.second;
            if (dist + wt < distance[neighbour])
            {
                pq.push({dist + wt, neighbour});
                distance[neighbour] = dist + wt;
            }
        }
    }
    return distance;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj_list = adj_list_maker(times, n);
    vector<int> distances = dijkastra(adj_list, n, k);
    int maxi = *max_element(distances.begin(), distances.end());
    return maxi == INT_MAX ? -1 : maxi;
}
int main()
{
    return 0;
}