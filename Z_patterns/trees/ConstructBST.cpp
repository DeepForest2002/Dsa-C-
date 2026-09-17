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

// create a global inOrdemap
unordered_map<int, int> inOrdeMpp;
int idx = 0;

TreeNode *BuildTree(vector<int> preOrder, int inLeft, int inRight)
{
    if (inLeft > inRight)
        return nullptr;
    int val = preOrder[idx++];
    TreeNode *root = new TreeNode(val);
    // find the index in InOrder
    int InOrder_Index = inOrdeMpp[val];
    root->left = BuildTree(preOrder, inLeft, InOrder_Index - 1);
    root->right = BuildTree(preOrder, InOrder_Index + 1, inRight);
    return root;
}

TreeNode *ConstructBT(vector<int> &preOrder, vector<int> &inOrder)
{
    for (int i = 0; i < inOrder.size(); i++)
    {
        inOrdeMpp[inOrder[i]] = i;
    }
    return BuildTree(preOrder, 0, inOrder.size() - 1);
}

int main()
{
    return 0;
}