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

int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if (lh == rh)
        return ((2 << (lh)) - 1);
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findLeftHeight(TreeNode *root)
{
    int h = 0;
    while (root)
    {
        h += 1;
        root = root->right;
    }
    return h;
}

int findRightHeight(TreeNode *node)
{
    int h = 0;
    while (node)
    {
        h += 1;
        node = node->right;
    }
    return h;
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