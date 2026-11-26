#include <iostream>

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    int floor = -1;

    while (root)
    {
        if (root->val == X)
        {
            return X;
        }

        if (root->val < X)
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return floor;
}

// https://www.naukri.com/code360/problems/floor-from-bst_920457