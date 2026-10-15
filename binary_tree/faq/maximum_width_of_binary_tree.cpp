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

int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    unsigned long long max_width = 0;
    std::queue<std::pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int n = q.size();
        unsigned long long mmin = q.front().second, first, last;

        for (int i = 0; i < n; i++)
        {
            unsigned long long curr_id = q.front().second - mmin;
            TreeNode *node = q.front().first;
            q.pop();

            if (i == 0)
            {
                first = curr_id;
            }
            if (i == (n - 1))
            {
                last = curr_id;
            }
            if (node->left)
            {
                q.push({node->left, (2 * curr_id + 1)});
            }
            if (node->right)
            {
                q.push({node->right, (2 * curr_id + 2)});
            }
        }
        max_width = std::max(max_width, (last - first + 1));
    }

    return static_cast<int>(max_width);
}

// https://leetcode.com/problems/maximum-width-of-binary-tree/