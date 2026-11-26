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

    traverse(root->left, result);

    result.push_back(root->val);

    traverse(root->right, result);
}

std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> result;

    traverse(root, result);

    return result;
}

// Iterative
std::vector<int> inorderTraversal(TreeNode *root)
{
    std::stack<TreeNode *> s;
    std::vector<int> result;
    TreeNode *curr = root;

    while (true)
    {
        if (curr != nullptr)
        {
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
            result.push_back(curr->val);
            curr = curr->right;
        }
    }

    return result;
}

// https://leetcode.com/problems/binary-tree-inorder-traversal/