#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    // Code here
    vector<int> res(V, INT_MAX);
    res[src] = 0;
    // vector of edges = [1,2,3] src,dest and weight
    // realaxation will happen for n-1 number of nodes
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int src1 = edges[j][0];
            int dest = edges[j][1];
            int wt = edges[j][2];
            if (res[src1] != INT_MAX && res[dest] > res[src1] + wt)
            {
                // relaxation
                res[dest] = res[src1] + wt;
            }
        }
    }
    // check for negative weight cycle
    for (int j = 0; j < edges.size(); j++)
    {
        int src1 = edges[j][0];
        int dest = edges[j][1];
        int wt = edges[j][2];
        if (res[src1] != INT_MAX && res[dest] < res[src1] + wt)
        {
            return {-1};
        }
    }
    return res;
}
int main()
{
    return 0;
}