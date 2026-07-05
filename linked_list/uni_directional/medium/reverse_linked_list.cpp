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

// My Solution
// Iterative
// Node *reverseList(Node *head)
// {
//     if ((head == nullptr) || (head->next == nullptr))
//     {
//         return head;
//     }

//     Node *before = nullptr;
//     Node *current = head;
//     Node *after = head->next;

//     while (after != nullptr)
//     {
//         current->next = before;
//         before = current;
//         current = after;
//         after = after->next;
//     }
//     current->next = before;
//     return current;
// }

// // Recursive
// Node *reverse(Node *current, Node *before)
// {
//     if (current == nullptr)
//     {
//         return before;
//     }

//     Node *after = current->next;
//     current->next = before;
//     before = current;
//     current = after;
//     return reverse(current, before);
// }

// Claude's And Striver's Solution
// Iterative
// Node *reverseList(Node *head)
// {
//     Node *before = nullptr;
//     Node *after = nullptr;
//     Node *current = head;

//     while (current != nullptr)
//     {
//         after = current->next;
//         current->next = before;
//         before = current;
//         current = after;
//     }
//     return before;
// }

// Recursive
Node *reverseList(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    Node *new_head = reverseList(head->next);
    Node *after = head->next;
    after->next = head;
    head->next = nullptr;
    return new_head;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 7};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    head = reverseList(head);
    traverseLinkedList(head);
    return 0;
}

// https://leetcode.com/problems/reverse-linked-list/submissions/2057010563/