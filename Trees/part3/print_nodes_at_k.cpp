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

// approach - map all the parentNodes of each node , 2-> take a queue and visited hash and traverse them with some conditions

void map_parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_map)
{
    // bfs search
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto currNode = q.front();
        q.pop();
        if (currNode->left)
        {
            parent_map[currNode->left] = currNode;
            q.push(currNode->left);
        }
        if (currNode->right)
        {
            parent_map[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }
    return;
}

vector<int> find_nodes(TreeNode *root, TreeNode *target, unordered_map<TreeNode *, TreeNode *> parent_map, int k)
{
    queue<TreeNode *> q;
    unordered_set<TreeNode *> visited;
    q.push(target);
    visited.insert(target);
    int currLevel = 0;
    while (!q.empty())
    {
        int size = q.size();
        // if we reach the current level break
        if (currLevel++ == k)
            break;

        // explore all the nodes at current level
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            // check each and every node
            if (node->left && visited.find(node->left) == visited.end())
            {
                visited.insert(node->left);
                q.push(node->left);
            }

            // explore the right side
            if (node->right && visited.find(node->right) == visited.end())
            {
                visited.insert(node->right);
                q.push(node->right);
            }

            // explore the parent node;
            if (parent_map.count(node) && visited.find(parent_map[node]) == visited.end())
            {
                q.push(parent_map[node]);
                visited.insert(parent_map[node]);
            }
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front()->data);
        q.pop();
    }
    return result;
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    if (root == nullptr)
        return {};
    unordered_map<TreeNode *, TreeNode *> parent_map;
    // map all the parent node
    map_parent(root, parent_map);

    return find_nodes(root, target, parent_map, k);
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