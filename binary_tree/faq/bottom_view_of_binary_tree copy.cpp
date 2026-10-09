#include <iostream>

template <typename T>

class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

std::vector<int> bottomView(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return {};
    }

    std::unordered_map<int, int> bottomNode;
    std::queue<std::pair<TreeNode<int> *, int>> q;

    q.push({root, 0});

    int minHD = 0; // smallest horizontal distance
    int maxHD = 0; // largest horizontal distance

    while (!q.empty())
    {
        auto [node, hd] = q.front();
        q.pop();

        bottomNode[hd] = node->data;

        if (node->left != nullptr)
        {
            int leftHD = hd - 1;

            q.push({node->left, leftHD});

            minHD = std::min(minHD, leftHD);
        }

        if (node->right != nullptr)
        {
            int rightHD = hd + 1;

            q.push({node->right, rightHD});

            maxHD = std::max(maxHD, rightHD);
        }
    }

    std::vector<int> answer;

    for (int hd = minHD; hd <= maxHD; hd++)
    {
        answer.push_back(bottomNode[hd]);
    }

    return answer;
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
    TreeNode<int> *root = new TreeNode<int>(1);

    // Level 1
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);

    // Level 2
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    // root->right->left is -1 (nullptr)
    root->right->right = new TreeNode<int>(6);

    // Level 3
    // root->left->left->left is -1 (nullptr)
    root->left->left->right = new TreeNode<int>(7);
    // root->left->right children are both -1 (nullptr)
    root->right->right->left = new TreeNode<int>(8);
    // root->right->right->right is -1 (nullptr)

    // Level 4
    root->left->left->right->left = new TreeNode<int>(9);
    // root->left->left->right->right is -1 (nullptr)
    // root->right->right->left->left is -1 (nullptr)
    root->right->right->left->right = new TreeNode<int>(11);

    // Level 5
    root->left->left->right->left->left = new TreeNode<int>(10);
    // root->left->left->right->left->right is -1 (nullptr)

    std::vector<int> result = bottomView(root);
    print(result);

    return 0;
}

// https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401?leftPanelTabValue=SUBMISSION