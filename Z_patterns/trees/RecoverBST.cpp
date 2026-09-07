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

TreeNode *m1first = nullptr;
TreeNode *m1second = nullptr;
TreeNode *m2first = nullptr;
TreeNode *m2second = nullptr;
int m = 0;
TreeNode *prevNode = nullptr;
void func(TreeNode *root)
{
    if (!root)
        return;
    func(root->left);
    if (!prevNode)
        prevNode = root;
    else
    {
        if (root->val <= prevNode->val)
        {
            if (m == 0)
            {
                m1first = prevNode;
                m1second = root;
                m += 1;
            }
            else
            {
                m2first = prevNode;
                m2second = root;
                m += 1;
            }
            prevNode = root;
        }
    }
    func(root->right);
}

TreeNode *RecoverBST(TreeNode *root)
{
    if (!root)
        return root;

    func(root);
    if (m == 1)
        swap(m1first->val, m1second->val);
    else
        swap(m1first->val, m2second->val);
    return root;
}

int main()
{
    return 0;
}