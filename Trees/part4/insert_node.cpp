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

TreeNode *Insert_node(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    TreeNode *curr = root;
    while (true)
    {
        if (val >= curr->data)
        {
            if (curr->right)
                curr = curr->right;
            else
                curr->right = new TreeNode(val);
            break;
        }
        else
        {
            if (curr->left)
                curr = curr->left;
            else
                curr->left = new TreeNode(val);
            break;
        }
    }
    return root;
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
    // cout << Search(root, 10);
    return 0;
}