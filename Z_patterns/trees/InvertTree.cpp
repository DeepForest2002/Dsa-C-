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

void count_nodes(Node *root, int *count)
{
    if (!root)
        return;
    count_nodes(root->left, count);
    count++;
    count_nodes(root->right, count);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    int count = 0;
    count_nodes(root, &count);
    cout << count;
    return 0;
}