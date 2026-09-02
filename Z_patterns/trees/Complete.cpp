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
bool isComplete(TreeNode *root)
{
    if (!root)
        return true;
    bool nullSeen = false;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *top = q.front();
        q.pop();
        if (top == nullptr)
            nullSeen = true;
        else
        {
            if (nullSeen)
                return false;
            q.push(top->left);
            q.push(top->right);
        }
    }
    return true;
}

int main()
{
    return 0;
}