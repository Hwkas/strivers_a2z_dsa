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

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
    {
        return {};
    }

    std::vector<std::vector<int>> result;
    std::queue<TreeNode *> q;
    bool leftToRight = true;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        std::vector<int> level(n);

        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }

            level[(leftToRight) ? i : n - i - 1] = curr->val;
        }

        result.push_back(level);
        leftToRight = !leftToRight;
    }

    return result;
}

void print(std::vector<std::vector<int>> &arr)
{
    for (auto temp : arr)
    {
        int size = temp.size();
        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
            std::cout << temp[i] << ((i == (size - 1)) ? "" : ", ");
        }
        std::cout << "] " << std::endl;
    }
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> traversal = zigzagLevelOrder(root);
    print(traversal);

    return 0;
}

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/2164325787/