#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

bool Search(TreeNode *root, int val)
{
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        if (curr->data == val)
            return true;
        else if (curr->data < val)
            curr = curr->right;
        else
            curr = curr->left;
    }
    return false;
}

// find floor and ceiling in a Binary Tree 



int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->right = new TreeNode(12);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    cout << Search(root, 10);
    return 0;
}