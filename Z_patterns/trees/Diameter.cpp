#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};
int res = 0;
int findHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    int sum = left + right;
    res = max(sum, res);
    return 1 + max(left, right);
}

int diameter(TreeNode *root)
{
    int height = findHeight(root);
    return res;
}

int main()
{
    return 0;
}