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

bool SameTree(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->data != root2->data)
        return false;
    bool left = SameTree(root1->left, root2->left);
    if (!left)
        return false;
    bool right = SameTree(root1->right, root2->right);
    if (!right)
        return false;
    return true;
}

int main()
{

    return 0;
}