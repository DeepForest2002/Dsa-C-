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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // take a map <vertical, <level and element>>
    map<int, map<int, multiset<int>>> mpp;
    // take a queue to store <TreeNode,vertical and level>
    queue<pair<TreeNode *, pair<int, int>>> q;

    // first push the first element
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.first;
        int v = p.second.first;
        int l = p.second.second;

        // insert left and right
        mpp[v][l].insert(node->data);
        if (node->left)
            q.push({node->left, {v - 1, l + 1}});
        if (node->right)
            q.push({node->right, {v + 1, l + 1}});
    }
    vector<vector<int>> ans;
    for (auto el : mpp)
    {
        vector<int> col;
        for (auto el2 : el.second)
        {
            col.insert(col.end(), el2.second.begin(), el2.second.end());
        }
        ans.push_back(col);
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
