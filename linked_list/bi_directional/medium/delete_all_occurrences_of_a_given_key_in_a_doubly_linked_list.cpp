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

Node *deleteAllOccurrences(Node *head, int k)
{
    if ((head == nullptr))
    {
        return head;
    }

    Node *before = nullptr, *after = nullptr, *current = head;

    while (current != nullptr)
    {
        after = current->next;
        if (current->data == k)
        {
            if (after != nullptr)
            {
                after->previous = before;
            }
            if (before != nullptr)
            {
                before->next = after;
            }
            if (current == head)
            {
                head = after;
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
    std::vector<int> v = {2, 2, 3};
    Node *head = arrayToDoublyLinkedList(v);
    traverseForward(head);
    head = deleteAllOccurrences(head, 2);
    traverseForward(head);
    return 0;
}

// https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461