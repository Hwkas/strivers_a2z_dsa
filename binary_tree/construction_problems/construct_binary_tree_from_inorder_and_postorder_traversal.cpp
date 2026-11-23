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

TreeNode *solve(
    const std::vector<int> &inorder,
    const std::vector<int> &postorder,
    const std::unordered_map<int, int> &mp,
    int postorder_idx,
    int inorder_start_idx,
    int inorder_end_idx)
{
    if (postorder_idx < 0 || inorder_start_idx == inorder_end_idx)
    {
        return nullptr;
    }

    int i = mp.at(postorder[postorder_idx]);

    TreeNode *curr = new TreeNode(inorder[i]);

    int right_size = inorder_end_idx - i;
    curr->right = solve(inorder, postorder, mp, postorder_idx - 1, i + 1, inorder_end_idx);
    curr->left = solve(inorder, postorder, mp, postorder_idx - right_size, inorder_start_idx, i);

    return curr;
}

TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
{
    std::unordered_map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return solve(inorder, postorder, mp, postorder.size() - 1, 0, inorder.size());
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
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    std::vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *curr = buildTree(inorder, postorder);

    printLevelOrder(curr);
}

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/