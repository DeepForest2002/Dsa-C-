#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

void traverse(Node *root, vector<int> &ans, int l)
{
    if (root == nullptr)
        return;
    if (ans.size() == l)
        ans.push_back(root->data);
    traverse(root->right, ans, l + 1);
    traverse(root->left, ans, l + 1);
}

vector<int> righ_side_traverse(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    traverse(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(6);
    root->right->right->right = new Node(7);
    return 0;
}