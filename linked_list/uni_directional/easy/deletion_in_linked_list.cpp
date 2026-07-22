#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data_param, Node *next_param = nullptr) : data(data_param), next(next_param) {}
};

Node<int> *arrayToLinkedList(std::vector<int> &v)
{
    Node<int> *head = new Node<int>(v[0]);
    Node<int> *tail = head;
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        Node<int> *temp = new Node<int>(v[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
};

void traverseLinkedList(Node<int> *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << ((head->next != nullptr) ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

Node<int> *deleteHead(Node<int> *head)
{
    if (head == nullptr)
    {
        return head;
    }
    Node<int> *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// https://www.naukri.com/code360/problems/delete-node-of-linked-list_8160463?leftPanelTabValue=SUBMISSION
Node<int> *deleteTail(Node<int> *head)
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

    Node<int> *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node<int> *deleteKthNode(Node<int> *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (k == 1)
    {
        Node<int> *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int index = 1;
    Node<int> *previous_node = nullptr;
    Node<int> *current_node = head;

    while (index <= k && current_node != nullptr)
    {
        if (index == k)
        {
            previous_node->next = current_node->next;
            delete current_node;
            break;
        }
        previous_node = current_node;
        current_node = current_node->next;
        index++;
    }
    return head;
}

Node<int> *deleteNodeWithVlaueK(Node<int> *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (k == head->data)
    {
        Node<int> *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node<int> *previous_node = nullptr;
    Node<int> *current_node = head;

    while (current_node != nullptr)
    {
        if (k == current_node->data)
        {
            previous_node->next = current_node->next;
            delete current_node;
            break;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    return head;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 7};
    Node<int> *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthNode(head, 5);
    head = deleteNodeWithVlaueK(head, 9);
    traverseLinkedList(head);
    return 0;
}