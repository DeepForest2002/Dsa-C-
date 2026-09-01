#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int val, TreeNode *right, TreeNode *left)
    {
        this->val = val;
        this->right = right;
        this->left = left;
    }
};

vector<vector<int>> res;
vector<int> path;
void func(TreeNode *root, int sum, int targetSum)
{
    if (root == nullptr)
        return;
    sum += root->val;
    path.push_back(root->val);
    if (!root->left && !root->right)
    {
        if (sum == targetSum)
            res.push_back(path);
        path.pop_back();
        return;
    }
    func(root->left, sum, targetSum);
    func(root->right, sum, targetSum);
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    func(root, 0, targetSum);
    return res;
}

int main()
{
    return 0;
}