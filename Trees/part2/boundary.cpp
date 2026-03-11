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

bool checkisLeaf(TreeNode *node)
{
    if (node->left == nullptr && node->right == nullptr)
        return true;
    else
        return false;
}

void add_left(TreeNode *root, vector<int> &result)
{
    TreeNode *curr = root->left;
    while (curr)
    {
        if (!checkisLeaf(curr))
            result.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void preorder(TreeNode *root, vector<int> &result)
{
    if (checkisLeaf(root))
    {
        result.push_back(root->data);
        return;
    }
    preorder(root->left, result);
    preorder(root->right, result);
}
void add_right(TreeNode *root, vector<int> result)
{
    TreeNode *curr = root->right;
    vector<int> vec;
    while (curr)
    {
        if (!checkisLeaf(root))
            vec.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        result.push_back(vec[i]);
    }
}

vector<int> Boundary_Traversal(TreeNode *root)
{
    vector<int> result;
    if (root == nullptr)
        return result;
    // check if root is leaf or not
    if (!checkisLeaf(root))
        result.push_back(root->data);
    // add left
    add_left(root, result);
    preorder(root, result);
    add_right(root, result);
    return result;
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