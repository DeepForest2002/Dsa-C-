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

TreeNode *findStartNode(TreeNode *root, int start, unordered_map<TreeNode *, TreeNode *> &mpp)
{
    // apply bfs traversal
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *res;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->data == start)
            res = node;
        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }

    return res;
}

int find_time(unordered_map<TreeNode *, TreeNode *> &mpp, TreeNode *res)
{
    // make a queue and a visited map
    queue<TreeNode *> q;
    unordered_map<TreeNode *, int> visited;
    int maxi = 0;
    q.push(res);
    visited[res] = 1;
    while (!q.empty())
    {
        int size = q.size();
        int fl = 0;
        // i have to concurrently process this nodes
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            // check left right and up
            if (node->left && !visited[node->left])
            {
                visited[node->left] = 1;
                q.push(node->left);
                fl = 1;
            }
            if (node->right && !visited[node->right])
            {
                visited[node->right] = 1;
                q.push(node->right);
                fl = 1;
            }

            if (mpp[node] && !visited[mpp[node]])
            {
                visited[mpp[node]] = 1;
                q.push(mpp[node]);
                fl = 1;
            }
        }
        if (fl)
            maxi += 1;
    }
    return maxi;
}

int MinimumTime(TreeNode *root, int start)
{
    // map all the parent and child nodes
    unordered_map<TreeNode *, TreeNode *> parent_map;
    TreeNode *res_node = findStartNode(root, start, parent_map);
    // pass the map and target node here
    int minTime = find_time(parent_map, res_node);
    return minTime;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(7);
    root->right->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    cout << MinimumTime(root, 2);
    return 0;
}