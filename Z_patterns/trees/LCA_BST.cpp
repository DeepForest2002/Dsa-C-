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

void func(Node *root, Node *p, Node *q)
{
    // case 1
    if (root == nullptr)
        return;
    else if (root->data == p->data || root->data == q->data)
    {
        ans = root;
        return;
    } // case 2
    else if (root->data < p->data && root->data < q->data)
    {
        // go for right
        func(root->right, p, q);
    } // case 3
    else if (root->data > p->data && root->data > q->data)
    {
        // go left
        func(root->left, p, q);
    } // case 4
    else
    {
        // spliting point case -5
        ans = root;
        return;
    }
}

Node *Lca(Node *root, Node *p, Node *q)
{
    func(root, p, q);
    return ans;
}

int main()
{
    return 0;
}