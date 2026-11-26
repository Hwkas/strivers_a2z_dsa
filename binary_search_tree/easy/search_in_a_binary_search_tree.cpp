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

// My Solution
TreeNode *searchBST(TreeNode *root, int val)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->val == val)
    {
        return root;
    }
    else if (root->val > val)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
}

// Striver's Solution
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root && root->val != val)
    {
        root = root->val > val ? root->left : root->right;
    }

    return root;
}

// https://leetcode.com/problems/search-in-a-binary-search-tree/