#include <iostream>

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node(
        int data_param,
        Node *previous_param = nullptr,
        Node *next_param = nullptr) : data(data_param), previous(previous_param), next(next_param) {}
};

Node *arrayToDoublyLinkedList(std::vector<int> &v)
{
    if (v.empty())
    {
        return nullptr;
    }

    Node *head = new Node(v[0]);
    Node *temp = head;
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(v[i], temp);
        temp = temp->next;
    }
    return head;
}

void traverseForward(Node *head)
{
    if (head != nullptr)
    {
        while (head != nullptr)
        {
            std::cout << head->data << ((head->next != nullptr) ? " -> " : "");
            head = head->next;
        }

        std::cout << std::endl;
    }
}

Node *deleteDuplicates(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    Node *before = head, *after = nullptr, *current = head->next;

    while (current != nullptr)
    {
        after = current->next;
        if (before->data == current->data)
        {
            before->next = after;
            if (after != nullptr)
            {
                after->previous = before;
            }
            delete current;
        }
        else
        {
            before = current;
        }
        current = after;
    }
    return head;
}

int main()
{
    std::vector<int> v = {1, 1, 1, 2};
    Node *head = arrayToDoublyLinkedList(v);
    traverseForward(head);
    head = deleteDuplicates(head);
    traverseForward(head);
    return 0;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/