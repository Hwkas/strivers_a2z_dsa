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

Node *deleteHead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    head->previous = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

// https://www.naukri.com/code360/problems/delete-last-node-of-a-doubly-linked-list_8160469?leftPanelTabValue=SUBMISSION
Node *deleteTail(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteKthNode(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->previous = nullptr;
        }
        delete temp;
        return head;
    }

    int index = 1;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        if ((index + 1) == k)
        {
            Node *node_to_delete = temp->next;
            temp->next = node_to_delete->next;
            if (node_to_delete->next != nullptr)
            {
                node_to_delete->next->previous = temp;
            }
            delete node_to_delete;
            break;
        }
        temp = temp->next;
        index++;
    }
    return head;
}

void deleteNode(Node *node)
{
    Node *next_node = node->next;
    Node *prevous_node = node->previous;

    if (node->next == nullptr)
    {
        prevous_node->next = nullptr;
    }
    else
    {
        prevous_node->next = next_node;
        next_node->previous = prevous_node;
    }

    delete node;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 9, 7};
    Node *head = arrayToDoublyLinkedList(v);
    traverseForward(head);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthNode(head, 6);
    deleteNode(head->next);
    traverseForward(head);
    return 0;
}