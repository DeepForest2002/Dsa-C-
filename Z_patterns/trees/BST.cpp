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

Node *ans = nullptr;
void *SearchBST(Node *root, int data)
{
    if (!root)
        return;
    if (root->data == data)
    {
        ans = root;
        return;
    }
    if (root->data > data)
        SearchBST(root->left, data);
    else
        SearchBST(root->right, data);
}

int main()
{

    return 0;
}