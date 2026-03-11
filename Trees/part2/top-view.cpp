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

vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    queue<pair<TreeNode *, int>> q;
    map<int, int> mpp;
    q.push({root, 0});
    while (!q.empty())
    {
        // take the first element out
        auto p = q.front();
        q.pop();
        int l = p.second;
        TreeNode *node = p.first;
        // if the line is not present the push this with line
        if (mpp.find(l) == mpp.end())
            mpp[l] = node->data;
        if (node->left)
            q.push({node->left, l - 1});
        if (node->right)
            q.push({node->right, l + 1});
    }
    for (auto el : mpp)
    {
        ans.push_back(el.second);
    }
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
