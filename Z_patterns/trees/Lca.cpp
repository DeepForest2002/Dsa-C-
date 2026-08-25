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

Node *ans = nullptr;

int func(Node *root, Node *p, Node *q)
{
    if (!root)
        return 0;
    int left = func(root->left, p, q);
    int right = func(root->right, p, q);
    int self = 0;
    if (root == p || root == q)
        self = 1;
    int total = self + right + left;
    if (total == 2 && ans == nullptr)
        ans = root;
    return total;
}

Node *Lca(Node *root, Node *p, Node *q)
{
    int f = func(root, p, q);
    return ans;
}

int main()
{
    return 0;
}