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
std::vector<int> inorderTraversal(TreeNode *root)
{
    std::vector<int> inorder;

    while (root)
    {
        if (root->left)
        {
            TreeNode *curr = root->left;

            while (curr->right && curr->right != root)
            {
                curr = curr->right;
            }

            if (!curr->right)
            {
                curr->right = root;
                root = root->left;
            }
            else
            {
                curr->right = nullptr;
                inorder.push_back(root->val);
                root = root->right;
            }
        }
        else
        {
            inorder.push_back(root->val);
            root = root->right;
        }
    }

    return inorder;
}

void print(std::vector<int> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] " << std::endl;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->right = new TreeNode(6);

    std::vector<int> inorder = inorderTraversal(root);

    print(inorder);

    return 0;
}

// https://leetcode.com/problems/binary-tree-inorder-traversal/