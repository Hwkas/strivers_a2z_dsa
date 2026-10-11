#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Brute Force Approach
// void findPath(
//     TreeNode *root,
//     TreeNode *p,
//     TreeNode *q,
//     std::vector<TreeNode *> &v,
//     std::vector<std::vector<TreeNode *>> &result)
// {
//     if (!root || (result.size() == 2))
//     {
//         return;
//     }

//     v.push_back(root);

//     if ((root->val == p->val) || root->val == q->val)
//     {
//         result.push_back(v);
//     }

//     findPath(root->left, p, q, v, result);
//     findPath(root->right, p, q, v, result);

//     v.pop_back();
// }

// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
// {
//     std::vector<TreeNode *> v;
//     std::vector<std::vector<TreeNode *>> result;

//     findPath(root, p, q, v, result);

//     int i = 0;

//     while (
//         (i < result[0].size()) &&
//         (i < result[1].size()) &&
//         (result[0][i]->val == result[1][i]->val))
//     {
//         i++;
//     }

//     return result[0][i - 1];
// }

// Optimal Approach
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if ((root == nullptr) || (root == p) || (root == q))
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (!left)
    {
        return right;
    }
    else if (!right)
    {
        return left;
    }
    else
    {
        return root;
    }
}

int main()
{
    TreeNode *root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *lca = lowestCommonAncestor(root, root->left, root->right);

    std::cout << "lowestCommonAncestor: " << lca->val << std::endl;

    return 0;
}

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
