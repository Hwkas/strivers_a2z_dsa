#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data_param, Node *next_param = nullptr) : data(data_param), next(next_param) {}
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
}

void traverseLinkedList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << ((head->next != nullptr) ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

Node *insertHead(Node *head, int val)
{
    return new Node(val, head);
}

Node *insertTail(Node *head, int val)
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

    temp->next = new Node(val);
    return head;
}

Node *insertionAtKthNode(Node *head, int k, int val)
{
    if ((head == nullptr) || (k == 1))
    {
        return ((k == 1) ? new Node(val, head) : head);
    }

    int index = 1;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (index == (k - 1))
        {
            temp->next = new Node(val, temp->next);
            break;
        }
        index++;
        temp = temp->next;
    }
    return head;
}

Node *insertionBeforeNodeWithValueK(Node *head, int k, int val)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->data == k)
    {
        return new Node(val, head);
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        if (temp->next->data == k)
        {
            temp->next = new Node(val, temp->next);
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 7};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    // head = insertHead(head, 1);
    // head = insertTail(head, 10);
    // head = insertionAtKthNode(head, 6, 10);
    head = insertionBeforeNodeWithValueK(head, 7, 10);
    traverseLinkedList(head);
    return 0;
}