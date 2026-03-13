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

bool check_symmetrical_help(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
    {
        return (left == right);
    }
    if (left->data != right->data)
        return false;
    // right subtree= root,left,right
    // left subtree = root,right,left
    return check_symmetrical_help(left->left, right->right) && check_symmetrical_help(left->right, right->left);
}

bool check_symmetrical(TreeNode *root)
{
    return check_symmetrical_help(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return 0;
}