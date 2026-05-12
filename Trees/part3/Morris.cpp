#include<bits/stdc++.h>
using namespace std;


class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        
        TreeNode(int data){
            this->data = data;
            this->left = this->right = nullptr;
        }
};


vector<int>Inorder(TreeNode *root){
    if(root==nullptr)
        return {};

    vector<int> InOrder;
    TreeNode *curr = root;
    while(!curr){
        //1st case if the left side is nullptr
        if(curr->left==nullptr){
            InOrder.push_back(curr->data);
            curr = curr->right;
        }else{
            //2nd case point the rightmost node of left subtree to the curr node
            TreeNode *prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right==nullptr){
                prev->right = curr;
                //in case of preOrder we write PreOrder.push_back(curr->data)
                curr = curr->left;
            }
            else{
                prev->right = nullptr;
                InOrder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return InOrder;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    return 0;
}