#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive
void traverse(std::vector<TreeNode *> nodes, std::vector<std::vector<int>> &result)
{
    if (nodes.empty())
    {
        return;
    }

    std::vector<int> temp;
    std::vector<TreeNode *> next_nodes;

    for (const auto &i : nodes)
    {
        temp.push_back(i->val);

        if (i->left)
        {
            next_nodes.push_back(i->left);
        }
        if (i->right)
        {
            next_nodes.push_back(i->right);
        }
    }

    result.push_back(temp);
    traverse(next_nodes, result);
}

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<TreeNode *> nodes;
    std::vector<std::vector<int>> result;

    if (root != nullptr)
    {
        nodes.push_back(root);
        traverse(nodes, result);
    }

    return result;
}

// Iterative - Queue
std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> result;

    if (root == nullptr)
    {
        return result;
    }

    std::queue<TreeNode *> q;

    q.push(root);

    int count = q.size();

    while (!q.empty())
    {
        std::vector<int> level;
        int n = q.size();

        while (n > 0)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }

            level.push_back(curr->val);
            n--;
        }

        result.push_back(level);
    }

    return result;
}

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/