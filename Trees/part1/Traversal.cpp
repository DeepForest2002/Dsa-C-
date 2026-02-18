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

void preOrderTraversal(vector<int> arr, Node *node)
{
    if (node == nullptr)
        return;
    arr.push_back(node->data);
    preOrderTraversal(arr, node->left);
    preOrderTraversal(arr, node->right);
}

vector<int> preOrder(Node *root)
{
    vector<int> arr;
    preOrderTraversal(arr, root);
    return arr;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    return 0;
}