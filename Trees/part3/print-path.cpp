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

bool getSolution(TreeNode *root, int target, vector<int> &ans)
{
    if (root == nullptr)
        return false;
    if (root->data == target)
        return true;
    ans.push_back(root->data);
    if (getSolution(root->left, target, ans) || getSolution(root->right, target, ans))
        return true;
    ans.pop_back();
    return false;
}

vector<int> find_solution(TreeNode *root, int target)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;
    getSolution(root, target, ans);
    return ans;
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