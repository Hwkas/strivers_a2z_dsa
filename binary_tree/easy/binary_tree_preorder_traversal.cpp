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
void traverse(TreeNode *root, std::vector<int> &result)
{
    if (root == nullptr)
    {
        return;
    }

    result.push_back(root->val);
    traverse(root->left, result);
    traverse(root->right, result);
}

std::vector<int> preorderTraversal(TreeNode *root)
{
    std::vector<int> result;

    traverse(root, result);

    return result;
}

// Iterative
std::vector<int> preorderTraversal(TreeNode *root)
{
    std::stack<TreeNode *> s;
    std::vector<int> result;
    TreeNode *curr = root;

    while (true)
    {
        if (curr != nullptr)
        {
            result.push_back(curr->val);
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty())
            {
                break;
            }

            curr = s.top();
            s.pop();
            curr = curr->right;
        }
    }

    return result;
}

// https://leetcode.com/problems/binary-tree-preorder-traversal/