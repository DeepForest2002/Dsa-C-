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

bool checkSymmetry(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->data != root2->data)
        return false;
    bool left = checkSymmetry(root1->left, root2->right);
    if (!left)
        return false;
    bool right = checkSymmetry(root1->right, root2->left);
    if (!right)
        return false;
    return true;
}

bool func(Node *root)
{
    if (!root)
        return true;
    return checkSymmetry(root->left, root->right);
}

int main()
{

    return 0;
}