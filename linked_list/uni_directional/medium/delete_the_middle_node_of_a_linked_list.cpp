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
Node *deleteMiddle(Node *head)
{
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *slow = head, *fast = head->next->next;

    while ((fast != nullptr) && (fast->next != nullptr))
    {
        fast = fast->next->next;
        slow = slow->next;
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
    head = deleteMiddle(head);
    traverseLinkedList(head);
    return 0;
}

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/