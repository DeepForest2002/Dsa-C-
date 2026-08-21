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

void PreOrder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data;
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
    return 0;
}