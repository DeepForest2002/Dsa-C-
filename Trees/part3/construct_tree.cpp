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

TreeNode *buildTree(vector<int> &preOrder, vector<int> inOrder)
{
    map<int, int> inMap;
    for (int i = 0; i < inOrder.size(); i++)
    {
        inMap[inOrder[i]] = i;
    }
    TreeNode *rootNode = build(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inMap);
    return rootNode;
}

TreeNode *build(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder, int inStart, int inEnd, map<int, int> &inMap)
{
    if (preStart > preEnd || inStart > inEnd)
        return nullptr;
    // create the root node
    TreeNode *root = new TreeNode(preOrder[preStart]);
    // find the node in Inorder
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;
    root->left = build(preOrder, preStart + 1, preStart + numsLeft, inOrder, inStart, inRoot - 1, inMap);
    root->right = build(preOrder, preStart + numsLeft + 1, preEnd, inOrder, inRoot + 1, inEnd, inMap);
    return root;
}

int main()
{
    vector<int> preOrder = {3, 9, 20, 15, 7};
    vector<int> inOrder = {9, 3, 15, 20, 7};
    return 0;
}