#include <iostream>

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// Recursive
void traverse(TreeNode *root, std::vector<std::vector<int>> &result)
{
    if (root == nullptr)
    {
        return;
    }

    result[1].push_back(root->data);

    traverse(root->left, result);

    result[0].push_back(root->data);

    traverse(root->right, result);

    result[2].push_back(root->data);
}

std::vector<std::vector<int>> getTreeTraversal(TreeNode *root)
{
    std::vector<std::vector<int>> result(3);

    traverse(root, result);

    return result;
}

// Iterative
std::vector<std::vector<int>> getTreeTraversal(TreeNode *root)
{
    std::vector<std::vector<int>> result(3);

    if (root == nullptr)
    {
        return result;
    }

    std::stack<std::pair<TreeNode *, int>> s;

    s.push({root, 1});

    while (!s.empty())
    {
        auto i = s.top();
        s.pop();

        if (i.second == 1)
        {
            result[1].push_back(i.first->data);
            i.second++;
            s.push(i);

            if (i.first->left != nullptr)
            {
                s.push({i.first->left, 1});
            }
        }
        else if (i.second == 2)
        {
            result[0].push_back(i.first->data);
            i.second++;
            s.push(i);

            if (i.first->right != nullptr)
            {
                s.push({i.first->right, 1});
            }
        }
        else
        {
            result[2].push_back(i.first->data);
        }
    }

    return result;
}

int main()
{
    return 0;
}

// https://www.naukri.com/code360/problems/tree-traversal_981269