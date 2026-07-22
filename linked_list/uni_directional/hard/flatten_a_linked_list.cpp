#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data, Node *next = nullptr, Node *child = nullptr) : data(data), next(next), child(child) {}
};

Node *mergeTwoLL(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while ((head1 != nullptr) && (head2 != nullptr))
    {
        if (head1->data < head2->data)
        {
            temp->child = head1;
            head1 = head1->child;
        }
        else
        {
            temp->child = head2;
            head2 = head2->child;
        }
        temp = temp->child;
        temp->next = nullptr;
    }

    temp->child = (head1 != nullptr) ? head1 : head2;
    return dummyNode->child;
}

Node *flattenLinkedList(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    Node *merged_head = flattenLinkedList(head->next);
    return mergeTwoLL(head, merged_head);
}

// https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655