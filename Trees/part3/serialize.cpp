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

string Serialize(TreeNode *root)
{
    if (!root)
        return "";
    string str;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (!node)
            str.append("#,");
        else
            str.append(to_string(node->data) + ',');
        if (node)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return str;
}

TreeNode *deSerialize(string data)
{
    if (data.length() == 0)
        return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
            node->left = nullptr;
        else
        {
            TreeNode *newNode = new TreeNode(stoi(str));
            node->left = newNode;
            q.push(newNode);
        }
        getline(s, str, ',');
        if (str == "#")
            node->right = nullptr;
        else
        {
            TreeNode *newNode = new TreeNode(stoi(str));
            node->right = newNode;
            q.push(newNode);
        }
    }
    return root;
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    cout << Serialize(root);
    return 0;
}