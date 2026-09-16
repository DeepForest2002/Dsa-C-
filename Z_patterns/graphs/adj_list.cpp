#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list()
{

    vector<int> vertices = {0, 1, 2, 3, 4, 5, 6, 7};
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

int main()
{
    vector<vector<int>> AdjList = adj_list();
    for (int i = 0; i < AdjList.size(); i++)
    {
        cout << i << "-";
        for (int j = 0; j < AdjList[i].size(); j++)
        {
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}