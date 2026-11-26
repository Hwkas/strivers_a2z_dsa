#include <iostream>

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

// My Solution
// std::pair<int, bool> evaluate(Node *root)
// {
//     if (root == nullptr)
//     {
//         return {0, true};
//     }

//     if ((root->left == nullptr) && (root->right == nullptr))
//     {
//         return {root->data, true};
//     }

//     auto left = evaluate(root->left);
//     auto right = evaluate(root->right);

//     bool child_sum_prop = false;

//     if ((left.second && right.second) && (left.first + right.first == root->data))
//     {
//         child_sum_prop = true;
//     }

//     return {root->data, child_sum_prop};
// }

// bool isParentSum(Node *root)
// {
//     return evaluate(root).second;
// }

// Optimal
bool isParentSum(Node *root)
{
    if ((!root) || (!root->left && !root->right))
    {
        return true;
    }

    int l = root->left ? root->left->data : 0;
    int r = root->right ? root->right->data : 0;

    return (l + r == root->data) && isParentSum(root->left) && isParentSum(root->right);
}

int main()
{
    return 0;
}

// https://www.naukri.com/code360/problems/children-sum-property_8357239?leftPanelTabValue=SUBMISSION
// https://takeuforward.org/practice/dsa/children-sum-property-in-binary-tree