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

int find_ans(Node *root, int &maxi)
{
    if (root == nullptr)
        return 0;
    int ls = max(0, find_ans(root->left, maxi));
    int rs = max(0, find_ans(root->right, maxi));
    maxi = root->data + ls + rs;
    return root->data + max(ls, rs);
}

int maxPathSum(Node *root)
{
    int maxi = INT_MIN;
    find_ans(root, maxi);
    return maxi;
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