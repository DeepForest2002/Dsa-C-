#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_mat()
{
    vector<int> vertices = {0, 1, 2, 3, 4, 5, 6, 7};
    int rows = vertices.size();
    int cols = vertices.size();
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
    vector<vector<int>> adj_matrix(rows, vector<int>(cols, 0));
    for (int i = 0; i < edges.size(); i++)
    {
        pair<int, int> p = edges[i];
        int src = p.first;
        int dest = p.second;
        adj_matrix[src][dest] = 1;
        adj_matrix[dest][src] = 1;
    }
    return adj_matrix;
}

int main()
{
    return 0;
}