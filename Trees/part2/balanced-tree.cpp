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

int checkHeight(Node *root)
{
    if (root == nullptr)
        return 0;
    int ls = checkHeight(root->left);
    if (ls == -1)
        return -1;
    int rs = checkHeight(root->right);
    if (rs == -1)
        return -1;
    if (abs(ls - rs) > 1)
        return -1;
    return 1 + max(ls, rs);
}

bool check_balance(Node *root)
{
    return checkHeight(root) != -1;
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