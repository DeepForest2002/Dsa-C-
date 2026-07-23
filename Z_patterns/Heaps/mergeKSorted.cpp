#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;
    Node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

struct cmp
{
    /* data */
    bool operator()(const Node &a, const Node &b)
    {
        return a.data > b.data;
    }
};

vector<int> mergeArrays(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({mat[i][0], i, 0});
    }
    vector<int> res;
    while (!pq.empty())
    {
        Node n = pq.top();
        pq.pop();
        int d = n.data;
        int r = n.row;
        int c = n.col;
        int col_size = mat[r].size();
        res.push_back(d);
        if (c < col_size - 1)
            pq.push({mat[r][c + 1], r, c + 1});
    }
    return res;
}

int main()
{
    vector<vector<int>> mat = {{1, 2}, {0, 1}};
    vector<int> merge = mergeArrays(mat);
    for (auto el : merge)
    {
        cout << el << "";
    }
    return 0;
}