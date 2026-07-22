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

Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head->next;

    while ((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *dummy_node = new Node(-1);
    Node *temp = dummy_node;

    while ((left != nullptr) && (right != nullptr))
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    temp->next = (left != nullptr) ? left : right;
    return dummy_node->next;
}

Node *sortList(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    Node *mid = findMiddle(head);
    Node *left = head, *right = mid->next;

    mid->next = nullptr;
    left = sortList(left);
    right = sortList(right);
    return merge(left, right);
}

Node *quicksort(Node *begin, Node *end)
{
    if (begin == end || begin->next == end)
    {
        return begin;
    }
    int pivot = begin->data;
    Node *prev = begin, *current = begin->next, *head = begin;
    while (current != end)
    {
        if (current->data < pivot)
        {
            prev->next = current->next;
            current->next = head;
            head = current;
            current = prev->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    head = quicksort(head, begin);
    begin->next = quicksort(begin->next, end);
    return head;
}

int main()
{
    std::vector<int> v = {4, 2, 1, 3};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    head = sortList(head);
    traverseLinkedList(head);
    return 0;
}

// https://leetcode.com/problems/sort-list/