#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data, TreeNode *left, TreeNode *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

stack<TreeNode *> asc;
stack<TreeNode *> desc;

TreeNode *getsmall()
{
    if (asc.empty())
        return nullptr;
    TreeNode *small = asc.top();
    asc.pop();
    TreeNode *righChild = small->right;
    while (righChild)
    {
        asc.push(righChild);
        righChild = righChild->left;
    }
    return small;
}

TreeNode *getBig()
{
    if (desc.empty())
        return nullptr;
    TreeNode *big = desc.top();
    desc.pop();
    TreeNode *leftChild = big->left;
    while (leftChild)
    {
        desc.push(leftChild);
        leftChild = leftChild->right;
    }
    return big;
}

bool findTarget(TreeNode *root, int k)
{
    // push to asc and desc
    TreeNode *t = root;
    while (t)
    {
        asc.push(t);
        t = t->left;
    }
    t = root;
    while (t)
    {
        desc.push(t);
        t = t->right;
    }

    TreeNode *small = getsmall();
    TreeNode *big = getBig();
    while (small && big && small != big && small->data <= big->data)
    {
        int sum = small->data + big->data;
        if (sum == k)
            return true;
        if (sum > k)
            big = getBig();
        else
            small = getsmall();
    }
    return false;
}

int main()
{
    return 0;
}