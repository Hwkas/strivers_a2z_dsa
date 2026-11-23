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

/*
    Inorder traversal visits nodes in Left → Root → Right order
    Preorder traversal visits nodes in Root → Left → Right order
*/

// My Solution
TreeNode *solve(
    const std::vector<int> &preorder,
    const std::vector<int> &inorder,
    const std::unordered_map<int, int> &mp,
    int preorder_idx,
    int inorder_start_idx,
    int inorder_end_idx)
{
    if (preorder_idx == preorder.size() || inorder_start_idx == inorder_end_idx)
    {
        return nullptr;
    }

    int i = mp.at(preorder[preorder_idx]);

    TreeNode *curr = new TreeNode(inorder[i]);

    int left_size = i - inorder_start_idx;
    curr->left = solve(preorder, inorder, mp, preorder_idx + 1, inorder_start_idx, i);
    curr->right = solve(preorder, inorder, mp, preorder_idx + 1 + left_size, i + 1, inorder_end_idx);

    return curr;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
{
    std::unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return solve(preorder, inorder, mp, 0, 0, inorder.size());
}

void printLevelOrder(TreeNode *root)
{
    if (!root)
    {
        std::cout << "[]\n";
        return;
    }

    std::vector<std::string> tokens;
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (curr)
        {
            tokens.push_back(std::to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        }
        else
        {
            tokens.push_back("null");
        }
    }

    while (!tokens.empty() && tokens.back() == "null")
    {
        tokens.pop_back();
    }

    std::cout << "[";
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        if (i > 0)
            std::cout << ",";
        std::cout << tokens[i];
    }
    std::cout << "]\n";
}

int main()
{
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *curr = buildTree(preorder, inorder);

    printLevelOrder(curr);
}

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/