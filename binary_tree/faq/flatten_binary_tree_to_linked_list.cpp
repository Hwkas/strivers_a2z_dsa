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

// Recursive Approach
// void reversePreorder(TreeNode *root, TreeNode *&previous)
// {
//     if (root == nullptr)
//     {
//         return;
//     }

//     reversePreorder(root->right, previous);
//     reversePreorder(root->left, previous);

//     root->right = previous;
//     root->left = nullptr;
//     previous = root;
// }

// void flatten(TreeNode *root)
// {
//     TreeNode *previous = nullptr;

//     reversePreorder(root, previous);
// }

// Iterative
// void flatten(TreeNode *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }

//     std::stack<TreeNode *> st;
//     st.push(root);

//     while (!st.empty())
//     {
//         TreeNode *curr = st.top();
//         st.pop();

//         if (curr->right)
//         {
//             st.push(curr->right);
//         }
//         if (curr->left)
//         {
//             st.push(curr->left);
//         }

//         if (!st.empty())
//         {
//             curr->right = st.top();
//         }
//         curr->left = nullptr;
//     }
// }

// Morris Traversal
void flatten(TreeNode *root)
{
    TreeNode *curr = root;

    while (curr)
    {
        if (curr->left)
        {
            TreeNode *previous = curr->left;

            while (previous->right)
            {
                previous = previous->right;
            }

            previous->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }

        curr = curr->right;
    }
}