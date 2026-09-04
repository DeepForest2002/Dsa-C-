#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

bool ans = true;
/*void func(TreeNode *root)
{
    if (!root)
        return;
    if ((root->left && root->val <= root->left->val) || (root->right && root->val >= root->right->val))
    {
        ans = false;
        return;
    }
    func(root->left);
    func(root->right);
}*/
TreeNode *before = nullptr;
void func(TreeNode *root)
{
    if (root == nullptr)
        return;
    func(root->left);
    if (!before)
    {
        before = root;
    }
    else
    {
        if (root->val <= before->val)
        {
            ans = false;
            before = root;
        }
    }
    func(root->right);
}

bool ValidateBst(TreeNode *root)
{
    func(root);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    bool ans = ValidateBst(root);
    cout << ans;
    return 0;
}