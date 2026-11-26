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
    traverse(root->right, result);
    result.push_back(root->val);
}

std::vector<int> postorderTraversal(TreeNode *root)
{
    std::vector<int> result;

    traverse(root, result);

    return result;
}

// Iterative
std::vector<int> postorderTraversal(TreeNode *root)
{
    std::stack<TreeNode *> s;
    std::vector<int> result;
    TreeNode *curr = root;

    if (curr == nullptr)
    {
        return result;
    }

    s.push(curr);

    while (!s.empty())
    {
        curr = s.top();
        s.pop();
        result.push_back(curr->val);

        if (curr->left != nullptr)
        {
            s.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            s.push(curr->right);
        }
    }

    std::reverse(result.begin(), result.end());

    return result;
}

// https://leetcode.com/problems/binary-tree-postorder-traversal/description/