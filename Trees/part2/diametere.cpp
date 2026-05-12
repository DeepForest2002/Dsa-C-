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

int height(TreeNode *root, int &diameter){
    if(root==nullptr)
        return 0;
    int ls = height(root->left,diameter);
    int rs = height(root->right,diameter);
    diameter = max(diameter, ls + rs);
    return 1 + max(ls, rs);
}

int Diameter(TreeNode *root){
    if(root==nullptr)
        return 0;
    int diametere = 0;
    height(root, diametere);
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