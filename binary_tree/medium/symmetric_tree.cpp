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

bool traverse(TreeNode *root1, TreeNode *root2)
{
    if ((root1 == nullptr) || (root2 == nullptr))
    {
        return root1 == root2;
    }

    if (root1->val != root2->val)
    {
        return false;
    }

    return traverse(root1->left, root2->right) && traverse(root1->right, root2->left);
}

bool isSymmetric(TreeNode *root)
{
    return traverse(root->left, root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);

    std::cout << isSymmetric(root) << std::endl;

    return 0;
}

// https://leetcode.com/problems/symmetric-tree/description/