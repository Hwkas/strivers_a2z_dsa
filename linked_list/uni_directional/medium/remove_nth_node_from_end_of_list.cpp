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
// int lengthOfLinkedList(Node *head)
// {
//     int length = 0;
//     while (head != nullptr)
//     {
//         head = head->next;
//         length++;
//     }
//     return length;
// }

// Node *removeNthFromEnd(Node *head, int n)
// {
//     int index = 1, index_to_delete = lengthOfLinkedList(head) - (n - 1);

//     Node *temp = head;

//     if (index_to_delete == 1)
//     {
//         temp = temp->next;
//         delete head;
//         return temp;
//     }

//     while (temp != nullptr)
//     {
//         if ((index + 1) == index_to_delete)
//         {
//             Node *node_to_delete = temp->next;
//             if (node_to_delete != nullptr)
//             {
//                 temp->next = node_to_delete->next;
//                 delete node_to_delete;
//             }
//         }
//         temp = temp->next;
//         index++;
//     }
//     return head;
// }

// Optimal Approach
Node *removeNthFromEnd(Node *head, int n)
{
    Node *slow = head, *fast = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == nullptr)
    {
        head = head->next;
        delete slow;
        return head;
    }

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *node_to_delete = slow->next;
    slow->next = slow->next->next;
    delete node_to_delete;
    return head;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    head = removeNthFromEnd(head, 6);
    traverseLinkedList(head);
    return 0;
}

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/