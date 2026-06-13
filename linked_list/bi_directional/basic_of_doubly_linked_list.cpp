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

std::pair<Node *, Node *> arrayToDoublyLinkedList(std::vector<int> &v)
{
    if (v.empty())
    {
        return {nullptr, nullptr};
    }

    Node *head = new Node(v[0]);
    Node *tail = head;
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(v[i], tail);
        tail = tail->next;
    }
    return {head, tail};
}

void traverseDoublyLinkedList(Node *head = nullptr, Node *tail = nullptr)
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

    if (tail != nullptr)
    {
        while (tail != nullptr)
        {
            std::cout << tail->data << ((tail->previous != nullptr) ? " -> " : "");
            tail = tail->previous;
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::vector<int> v = {2, 5, 8, 7};
    auto [head, tail] = arrayToDoublyLinkedList(v);
    traverseDoublyLinkedList(head, tail);
    return 0;
}