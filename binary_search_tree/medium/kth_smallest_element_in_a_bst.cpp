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
void solve(TreeNode *root, int k, std::stack<int> &s)
{
    if (!root || s.size() == k)
    {
        return;
    }

    solve(root->left, k, s);

    if (s.size() < k)
    {
        s.push(root->val);
    }

    solve(root->right, k, s);
}

int kthSmallest(TreeNode *root, int k)
{
    std::stack<int> s;

    solve(root, k, s);

    return s.top();
}

// Claude Solution
void solve(TreeNode *root, int &k, int &result)
{
    if (!root || k == 0)
        return;

    solve(root->left, k, result);

    if (k > 0 && --k == 0)
    {
        result = root->val;
    }

    solve(root->right, k, result);
}

int kthSmallest(TreeNode *root, int k)
{
    int result = -1; // sentinel if k is out of range
    solve(root, k, result);
    return result;
}

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/