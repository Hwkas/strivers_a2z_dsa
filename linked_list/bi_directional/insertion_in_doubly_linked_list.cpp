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

// https://www.naukri.com/code360/problems/introduction-to-doubly-linked-list_8160413?leftPanelTabValue=SUBMISSION
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

Node *insertBeforeHead(Node *head, int val)
{
    Node *new_head = new Node(val, nullptr, head);
    if (head != nullptr)
    {
        head->previous = new_head;
    }
    return new_head;
}

Node *insertAfterHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    Node *after = head->next;

    temp->next = after;
    if (after != nullptr)
    {
        after->previous = temp;
    }
    head->next = temp;
    return head;
}

Node *insertBeforeTail(Node *head, int val)
{
    if (head == nullptr)
    {
        return new Node(val);
    }

    if (head->next == nullptr)
    {
        head->previous = new Node(val, nullptr, head);
        return head->previous;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *before = temp->previous;
    Node *new_node = new Node(val, before, temp);
    before->next = new_node;
    temp->previous = new_node;
    return head;
}

// https://www.naukri.com/code360/problems/insert-at-end-of-doubly-linked-list_8160464?leftPanelTabValue=SUBMISSION
Node *insertAfterTail(Node *head, int val)
{
    if (head == nullptr)
    {
        return new Node(val);
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = new Node(val, temp);
    return head;
}

Node *insertBeforeKthNode(Node *head, int k, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (k == 1)
    {
        head->previous = new Node(val, nullptr, head);
        return head->previous;
    }

    int index = 1;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (index == k)
        {
            Node *new_node = new Node(val, temp->previous, temp);
            temp->previous->next = new_node;
            temp->previous = new_node;
            break;
        }
        temp = temp->next;
        index++;
    }
    return head;
}

Node *insertAfterKthNode(Node *head, int k, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    int index = 1;

    while (temp != nullptr)
    {
        if (index == k)
        {
            Node *new_node = new Node(val, temp, temp->next);
            if (temp->next != nullptr)
            {
                temp->next->previous = new_node;
            }
            temp->next = new_node;
            break;
        }
        temp = temp->next;
        index++;
    }
    return head;
}

void insertBeforeNode(Node *node, int val)
{
    Node *new_node = new Node(val, node->previous, node);
    if (node->previous != nullptr)
    {
        node->previous->next = new_node;
    }
    node->previous = new_node;
}

void insertAfterNode(Node *node, int val)
{
    Node *new_node = new Node(val, node, node->next);
    if (node->next != nullptr)
    {
        node->next->previous = new_node;
    }
    node->next = new_node;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 9, 7};
    Node *head = arrayToDoublyLinkedList(v);
    traverseForward(head);
    // head = insertBeforeHead(head, 1);
    // head = insertAfterHead(head, 3);
    // head = insertBeforeTail(head, 10);
    head = insertAfterTail(head, 10);
    // head = insertBeforeKthNode(head, 1, 10);
    // head = insertAfterKthNode(head, 2, 10);
    // insertBeforeNode(head->next->next->next->next, 10);
    // insertAfterNode(head->next->next->next->next, 10);
    traverseForward(head);
    return 0;
}