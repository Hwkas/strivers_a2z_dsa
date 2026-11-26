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
// std::pair<int, bool> evaluate(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return {0, true};
//     }

//     std::pair<int, bool> left = evaluate(root->left);
//     std::pair<int, bool> right = evaluate(root->right);

//     left.first++;
//     right.first++;

//     if (
//         (!left.second) ||
//         (!right.second) ||
//         (std::abs(left.first - right.first) > 1))
//     {
//         return {std::max(left.first, right.first), false};
//     }

//     return (left.first > right.first ? left : right);
// }

// bool isBalanced(TreeNode *root)
// {
//     return evaluate(root).second;
// }

// Striver's Solution
int evaluate(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = evaluate(root->left);

    if (left == -1)
    {
        return -1;
    }

    int right = evaluate(root->right);

    if (right == -1)
    {
        return -1;
    }

    return (std::abs(left - right) > 1) ? -1 : (std::max(left, right) + 1);
}

bool isBalanced(TreeNode *root)
{
    return evaluate(root) == -1 ? false : true;
}

int main()
{
    return 0;
}

// https://leetcode.com/problems/balanced-binary-tree/