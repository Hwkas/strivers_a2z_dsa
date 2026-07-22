#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data, Node *next = nullptr, Node *random = nullptr) : data(data), next(next), random(random) {}
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
Node *copyRandomList(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }

    Node *current = head, *after = nullptr, *head_copy = nullptr;

    // Create a copy
    while (current != nullptr)
    {
        after = current->next;
        current->next = new Node(current->data, after);
        current = after;
    }

    // Updating Random pointer of copy ll
    current = head;

    while (current != nullptr)
    {
        if (current->random != nullptr)
        {
            current->next->random = current->random->next;
        }
        else
        {
            current->next->random = nullptr;
        }
        current = current->next->next;
    }

    // Splitting original & copy ll
    current = head;
    head_copy = head->next;

    while (current != nullptr)
    {
        after = current->next;
        current->next = after->next;

        if (current->next != nullptr)
        {
            after->next = current->next->next;
        }
        else
        {
            after->next = nullptr;
        }

        current = current->next;
        after = after->next;
    }

    return head_copy;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    Node *head_copy = copyRandomList(head);
    traverseLinkedList(head_copy);
    return 0;
}

// https://leetcode.com/problems/copy-list-with-random-pointer/