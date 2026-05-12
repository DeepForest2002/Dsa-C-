#include <bits/stdc++.h>
#include <algorithm>
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

int widthOfBinaryTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    queue<pair<TreeNode *, long long>> q;
    int maxWidth = 0;
    q.push({root, 0});
    while (!q.empty())
    {
        int currSize = q.size();
        long long stIndex = q.front().second;
        long long endIndex = q.back().second;
        maxWidth = max(maxWidth, (int)(endIndex - stIndex + 1));
        for (int i = 0; i < currSize; i++)
        {
            auto currNode = q.front();
            q.pop();
            if (currNode.first->left)
                q.push({currNode.first->left, 2 * currNode.second + 1});
            if (currNode.first->right)
                q.push({currNode.first->right, 2 * currNode.second + 2});
        }
    }
    return maxWidth;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(9);
    cout << widthOfBinaryTree(root);
    return 0;
}