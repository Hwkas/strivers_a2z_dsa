#include <iostream>

template <typename T>

class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void leftTraversal(TreeNode<int> *root, std::vector<int> &result)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }

    result.push_back(root->data);

    if (root->left)
    {
        leftTraversal(root->left, result);
    }
    else
    {
        leftTraversal(root->right, result);
    }
}

void rightTraversal(TreeNode<int> *root, std::vector<int> &result)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }

    if (root->right)
    {
        rightTraversal(root->right, result);
    }
    else
    {
        rightTraversal(root->left, result);
    }

    result.push_back(root->data);
}

void inorderTraversal(TreeNode<int> *root, std::vector<int> &result)
{
    if (!root)
    {
        return;
    }

    inorderTraversal(root->left, result);

    if (!root->left && !root->right)
    {
        result.push_back(root->data);
    }

    inorderTraversal(root->right, result);
}

std::vector<int> traverseBoundary(TreeNode<int> *root)
{
    if (!root)
    {
        return {};
    }

    std::vector<int> result = {root->data};

    leftTraversal(root->left, result);
    inorderTraversal(root, result);
    rightTraversal(root->right, result);

    return result;
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
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(20);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(8);
    root->left->right->left = new TreeNode<int>(7);
    root->right->left = new TreeNode<int>(18);
    root->right->right = new TreeNode<int>(25);

    std::vector<int> result = traverseBoundary(root);
    print(result);

    return 0;
}

// https://www.naukri.com/code360/problems/boundary-traversal_790725