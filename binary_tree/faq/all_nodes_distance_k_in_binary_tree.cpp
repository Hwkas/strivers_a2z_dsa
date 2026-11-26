#include <iostream>
#include <unordered_set>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void markParent(TreeNode *root, std::unordered_map<TreeNode *, TreeNode *> &parent_track)
{
    if (!root)
    {
        return;
    }

    if (root->left)
    {
        parent_track[root->left] = root;
        markParent(root->left, parent_track);
    }

    if (root->right)
    {
        parent_track[root->right] = root;
        markParent(root->right, parent_track);
    }
}

std::vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    std::unordered_map<TreeNode *, TreeNode *> parent_track;
    std::unordered_set<TreeNode *> visited;
    std::queue<TreeNode *> q;
    std::vector<int> result;

    markParent(root, parent_track);
    q.push(target);
    visited.insert(target);

    int dist = 0;
    while (!q.empty() && dist < k)
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
        dist++;
    }

    while (!q.empty())
    {
        result.push_back(q.front()->val);
        q.pop();
    }

    return result;
}

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/