#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

Node *arrayToLinkedList(std::vector<int> &v)
{
    Node *head = new Node(v[0]);
    Node *tail = head;
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(v[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
};

void traverseLinkedList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << ((head->next != nullptr) ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

// Brute Force
// bool isPalindrome(Node *head)
// {
//     std::stack<int> stk;
//     Node *temp = head;

//     while (temp != nullptr)
//     {
//         stk.push(temp->data);
//         temp = temp->next;
//     }

//     temp = head;

//     while (temp != nullptr)
//     {
//         if (stk.top() != temp->data)
//         {
//             return false;
//         }
//         stk.pop();
//         temp = temp->next;
//     }
//     return true;
// }

// Optimal Approach
Node *reverse(Node *head)
{
    Node *before = nullptr, *after = nullptr, *current = head;

    while (current != nullptr)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
    }
    return before;
}

bool isPalindrome(Node *head)
{
    Node *slow = head, *fast = head;

    while ((fast->next != nullptr) && (fast->next->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *first_head = head, *second_head = reverse(slow->next);

    while (second_head != nullptr)
    {
        if (first_head->data != second_head->data)
        {
            reverse(slow->next);
            return false;
        }
        first_head = first_head->next;
        second_head = second_head->next;
    }
    reverse(slow->next);
    return true;
}

int main()
{
    std::vector<int> v = {1, 2, 2, 1};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    std::cout << "Palindrome Linked List: " << (isPalindrome(head) ? "True" : "False") << std::endl;
    return 0;
}

// https://leetcode.com/problems/palindrome-linked-list/submissions/2058653043/