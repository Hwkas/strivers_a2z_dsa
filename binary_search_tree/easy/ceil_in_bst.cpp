#include <iostream>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ceil = -1;

    while (node)
    {
        if (node->data == x)
        {
            return node->data;
        }
        if (node->data > x)
        {
            ceil = node->data;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    return ceil;
}

// https://www.naukri.com/code360/problems/ceil-from-bst_920464