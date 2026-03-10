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

void zig_zag(TreeNode *root, vector<vector<int>> &ans)
{
    queue<TreeNode *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        vector<int> v;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            v.push_back(node->data);
        }
        if (flag == 0)
        {
            ans.push_back(v);
            flag = 1;
        }
        else
        {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            flag = 0;
        }
    }
}
vector<vector<int>> traversal(TreeNode *root)
{
    vector<vector<int>> ans;
    zig_zag(root, ans);
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
    vector<vector<int>> ans = traversal(root);
    for (auto element : ans)
    {
        for (auto el : element)
        {
            cout << el << " ";
        }
    }
    return 0;
}