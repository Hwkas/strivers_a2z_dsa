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

// https://www.naukri.com/code360/problems/count-nodes-of-linked-list_5884
int lengthOfLinkedList(Node *head)
{
    int length = 0;
    while (head != nullptr)
    {
        head = head->next;
        length++;
    }
    return length;
}

// https://www.naukri.com/code360/problems/search-in-a-linked-list_975381
int searchInLinkedList(Node *head, int k)
{
    while (head != nullptr)
    {
        if (head->data == k)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 7};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    std::cout << "Length of Linked List is " << lengthOfLinkedList(head) << "." << std::endl;
    return 0;
}
