#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void InvertTree(Node *root)
{
    if (root == nullptr)
        return;
    swap(root->left, root->right);
    InvertTree(root->left);
    InvertTree(root->right);
}

int main()
{

    return 0;
}