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
int findLength(Node *head)
{
    int length = 0;

    while (head != nullptr)
    {
        head = head->next;
        length++;
    }
    return length;
}

Node *rotateRight(Node *head, int k)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    k = k % findLength(head);

    if (k == 0)
    {
        return head;
    }

    Node *slow = head, *fast = head, *new_head = nullptr;

    while (k)
    {
        fast = fast->next;
        k--;
    }

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    new_head = slow->next;
    slow->next = nullptr;
    fast->next = head;
    return new_head;
}

// Striver's Solution
// Node *rotateRight(Node *head, int k)
// {
//     // If list is empty or has only one node, or no rotation is needed
//     if (!head || !head->next || k == 0)
//         return head;

//     // Initialize length and tail pointer
//     int length = 1;
//     Node *tail = head;

//     // Traverse to find the tail and length
//     while (tail->next)
//     {
//         tail = tail->next;
//         length++;
//     }

//     // Make it a circular linked list
//     tail->next = head;

//     // Effective rotations needed
//     k = k % length;

//     // Traverse to the new tail (length - k - 1 steps from head)
//     int stepsToNewTail = length - k;
//     Node *newTail = head;
//     for (int i = 1; i < stepsToNewTail; i++)
//     {
//         newTail = newTail->next;
//     }

//     // Set the new head
//     Node *newHead = newTail->next;

//     // Break the circle
//     newTail->next = NULL;

//     return newHead;
// }

int main()
{
    std::vector<int> v = {1, 2};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    head = rotateRight(head, 1);
    traverseLinkedList(head);
    return 0;
}

// https://leetcode.com/problems/rotate-list/