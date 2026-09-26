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
        this->left = this->right = nullptr;
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

int count_nodes(Node *root)
{
    if (!root)
        return 0;
    int left = count_nodes(root->left);
    int right = count_nodes(root->right);
    return 1 + left + right;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << count_nodes(root);
    return 0;
}