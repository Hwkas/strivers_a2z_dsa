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

// My Solution
// Node *reverseDLL(Node *head)
// {
//     if (head == nullptr || head->next == nullptr)
//     {
//         return head;
//     }

//     Node *temp = head;

//     while (temp->next != nullptr)
//     {
//         Node *before = temp->previous;
//         Node *after = temp->next;
//         temp->next = before;
//         temp->previous = after;
//         temp = after;
//     }
//     temp->next = temp->previous;
//     temp->previous = nullptr;
//     return temp;
// }

// Striver's Solution
Node *reverseDLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *before = nullptr;
    Node *temp = head;

    while (temp != nullptr)
    {
        before = temp->previous;
        temp->previous = temp->next;
        temp->next = before;
        temp = temp->previous;
    }
    return before->previous;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 9, 7};
    Node *head = arrayToDoublyLinkedList(v);
    traverseForward(head);
    head = reverseDLL(head);
    traverseForward(head);
    return 0;
}

// https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098?leftPanelTabValue=SUBMISSION