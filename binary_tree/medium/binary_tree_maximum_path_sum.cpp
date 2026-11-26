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
// int solve(TreeNode *root, int &max)
// {
//     if (root == nullptr)
//     {
//         return 0;
//     }

//     int left = solve(root->left, max);
//     int right = solve(root->right, max);

//     max = std::max(
//         {
//             max,
//             root->val,
//             left + root->val,
//             right + root->val,
//             left + right + root->val,
//         });

//     return std::max({root->val, left + root->val, right + root->val});
// }

// Striver's Solution
int solve(TreeNode *root, int &max)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = std::max(0, solve(root->left, max));
    int right = std::max(0, solve(root->right, max));

    max = std::max(max, left + right + root->val);

    return std::max(left, right) + root->val;
}

int maxPathSum(TreeNode *root)
{
    int max = INT_MIN;

    solve(root, max);

    return max;
}

int main()
{
    return 0;
}

// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/