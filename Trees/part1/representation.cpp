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

int main()
{
    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);
    return 0;
}