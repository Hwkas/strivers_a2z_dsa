#include <iostream>
#include <sstream>

template <typename T>

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

std::string vectorToString(const std::vector<int> &vec, const std::string &delimiter = " ")
{
    std::ostringstream oss;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        oss << vec[i];
        if (i != vec.size() - 1)
        {
            oss << delimiter;
        }
    }
    return oss.str();
}

void traverse(BinaryTreeNode<int> *root, std::vector<int> &v, std::vector<std::string> &result)
{
    if (!root)
    {
        return;
    }

    v.push_back(root->data);

    if ((!v.empty()) && (!root->left && !root->right))
    {
        result.push_back(vectorToString(v));
    }

    traverse(root->left, v, result);
    traverse(root->right, v, result);

    v.pop_back();
}

std::vector<std::string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    std::vector<std::string> result;
    std::vector<int> v;

    traverse(root, v, result);

    return result;
}

void print(std::vector<std::string> &arr)
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
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);

    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);

    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);

    std::vector<std::string> result = allRootToLeaf(root);

    print(result);

    return 0;
}

// https://www.naukri.com/code360/problems/all-root-to-leaf-paths-in-binary-tree._983599