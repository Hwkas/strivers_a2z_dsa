#include <iostream>
#include <unordered_set>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void markParent(
    TreeNode *root,
    std::unordered_map<TreeNode *, TreeNode *> &parent_track,
    TreeNode *&start_node,
    int start)
{
    if (!root)
    {
        return;
    }

    if (root->val == start)
    {
        start_node = root;
    }

    if (root->left)
    {
        parent_track[root->left] = root;
        markParent(root->left, parent_track, start_node, start);
    }

    if (root->right)
    {
        parent_track[root->right] = root;
        markParent(root->right, parent_track, start_node, start);
    }
}

int amountOfTime(TreeNode *root, int start)
{
    std::unordered_map<TreeNode *, TreeNode *> parent_track;
    std::unordered_set<TreeNode *> visited;
    std::queue<TreeNode *> q;

    TreeNode *start_node = nullptr;

    markParent(root, parent_track, start_node, start);
    q.push(start_node);
    visited.insert(start_node);

    int time = -1;
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left && visited.insert(curr->left).second)
            {
                q.push(curr->left);
            }
            if (curr->right && visited.insert(curr->right).second)
            {
                q.push(curr->right);
            }

            auto it = parent_track.find(curr);
            if (it != parent_track.end() && visited.insert(it->second).second)
            {
                q.push(it->second);
            }
        }
        time++;
    }

    return time;
}