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

int solve(TreeNode *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = solve(root->left, diameter);
    int right = solve(root->right, diameter);

    diameter = std::max(diameter, left + right);

    return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;

    solve(root, diameter);

    return diameter;
}

int main()
{
    return 0;
}

// https://leetcode.com/problems/diameter-of-binary-tree/description/