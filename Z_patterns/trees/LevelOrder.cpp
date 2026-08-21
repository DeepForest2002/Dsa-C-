#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data, Node *right, Node *left)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};

vector<vector<int>> LevelOrder(Node *node)
{
    vector<vector<int>> ans;
    if (node == nullptr)
        return ans;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        while (size--)
        {
            Node *top = q.front();
            q.pop();
            temp.push_back(top->data);
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    return 0;
}