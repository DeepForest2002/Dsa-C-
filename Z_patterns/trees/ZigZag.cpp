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

vector<vector<int>> LevelOrderZigZag(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool Left_to_Right = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *top = q.front();
            q.pop();
            int idx = Left_to_Right ? i : size - 1 - i;
            temp[idx] = top->data;
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
        ans.push_back(temp);
        Left_to_Right = !Left_to_Right;
    }
    return ans;
}

int main()
{
    return 0;
}