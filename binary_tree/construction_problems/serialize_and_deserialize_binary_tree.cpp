#include <iostream>
#include <sstream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
std::string serialize(TreeNode *root)
{
    if (!root)
    {
        return "";
    }

    std::string searilized_tree = "";
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (!curr)
        {
            searilized_tree.append("#,");
        }
        else
        {
            searilized_tree.append(std::to_string(curr->val) + ',');

            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return searilized_tree;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(std::string data)
{
    if (data.empty())
    {
        return nullptr;
    }

    std::stringstream ss(data);
    std::string substr;
    char dlm = ',';
    std::getline(ss, substr, dlm);

    std::queue<TreeNode *> q;

    TreeNode *root = new TreeNode(std::stoi(substr));
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        // Left
        std::getline(ss, substr, dlm);

        if (substr == "#")
        {
            curr->left = nullptr;
        }
        else
        {
            curr->left = new TreeNode(std::stoi(substr));
            q.push(curr->left);
        }

        // Right
        std::getline(ss, substr, dlm);

        if (substr == "#")
        {
            curr->right = nullptr;
        }
        else
        {
            curr->right = new TreeNode(std::stoi(substr));
            q.push(curr->right);
        }
    }

    return root;
}

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/