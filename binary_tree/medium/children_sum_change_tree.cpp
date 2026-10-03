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
};

void changeTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    int child = 0;

    child += root->left ? root->left->data : 0;
    child += root->right ? root->right->data : 0;

    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
        }

        if (root->right)
        {
            root->right->data = root->data;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;

    tot += root->left ? root->left->data : 0;
    tot += root->right ? root->right->data : 0;

    if (root->left || root->right)
    {
        root->data = tot;
    }
}

int main()
{
    return 0;
}

// https://www.naukri.com/code360/problems/childrensumproperty_790723