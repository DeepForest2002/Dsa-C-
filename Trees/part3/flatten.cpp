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
        this->left = this->right = nullptr;
    }
};

TreeNode *nextRight = nullptr;

void flatten(TreeNode *root)
{
    if (root == nullptr)
        return;
    flatten(root->right);
    flatten(root->left);
    root->left = nullptr;
    root->right = nextRight;
    nextRight = root;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    return 0;
}