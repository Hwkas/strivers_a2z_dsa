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
// TreeNode *deleteNode(TreeNode *root, int key)
// {
//     TreeNode *previous = nullptr;
//     TreeNode *curr = root;

//     while (curr)
//     {
//         if (curr->val == key)
//         {
//             if (curr == root)
//             {
//                 if (!root->left)
//                 {
//                     return root->right;
//                 }
//                 root = root->left;
//             }
//             else if (previous->left == curr)
//             {
//                 if (!curr->left)
//                 {
//                     previous->left = curr->right;
//                     return root;
//                 }
//                 previous->left = curr->left;
//             }
//             else
//             {
//                 if (!curr->left)
//                 {
//                     previous->right = curr->right;
//                     return root;
//                 }
//                 previous->right = curr->left;
//             }

//             if (!curr->right)
//             {
//                 return root;
//             }

//             TreeNode *node_to_place = curr->right;

//             curr = curr->left;

//             while (curr->right)
//             {
//                 curr = curr->right;
//             }

//             curr->right = node_to_place;

//             return root;
//         }

//         previous = curr;

//         if (curr->val > key)
//         {
//             curr = curr->left;
//         }
//         else
//         {
//             curr = curr->right;
//         }
//     }

//     return root;
// }

// Striver's Solution
TreeNode *helper(TreeNode *root)
{
    if (root->left == nullptr)
    {
        return root->right;
    }

    if (root->right == nullptr)
    {
        return root->left;
    }

    TreeNode *rightChild = root->right;
    TreeNode *leftChild = root->left;

    TreeNode *leftmostOfRight = rightChild;
    while (leftmostOfRight->left != nullptr)
    {
        leftmostOfRight = leftmostOfRight->left;
    }

    leftmostOfRight->left = leftChild;

    return rightChild;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->val == key)
    {
        return helper(root);
    }

    if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root->right = deleteNode(root->right, key);
    }

    return root;
}

// https://leetcode.com/problems/delete-node-in-a-bst/description/