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

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    TreeNode *new_node = new TreeNode(val);

    if (!root)
    {
        return new_node;
    }

    TreeNode *curr = root;

    while (curr)
    {
        if (curr->val > val)
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new_node;
                break;
            }
        }
        else
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new_node;
                break;
            }
        }
    }

    return root;
}

// https://leetcode.com/problems/insert-into-a-binary-search-tree/