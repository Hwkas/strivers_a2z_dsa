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

Node *oddEvenList(Node *head)
{
    if (
        (head == nullptr) ||
        (head->next == nullptr) ||
        (head->next->next == nullptr))
    {
        return head;
    }

    Node *odd = head, *even = head->next, *even_start = head->next;

    while ((even != nullptr) && (even->next != nullptr))
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = even_start;
    return head;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    head = oddEvenList(head);
    traverseLinkedList(head);
    return 0;
}

// https://leetcode.com/problems/odd-even-linked-list/