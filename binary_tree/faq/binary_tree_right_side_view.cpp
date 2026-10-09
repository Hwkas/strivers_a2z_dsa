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

void traverse(TreeNode *root, std::vector<int> &result, int depth)
{
    if (!root)
    {
        return;
    }

    if (depth == result.size())
    {
        result.push_back(root->val);
    }

    traverse(root->right, result, depth + 1);
    traverse(root->left, result, depth + 1);
}

std::vector<int> rightSideView(TreeNode *root)
{
    std::vector<int> result;

    traverse(root, result, 0);

    return result;
}

int main()
{
    return 0;
}

// https://leetcode.com/problems/binary-tree-right-side-view/submissions/2167555990/