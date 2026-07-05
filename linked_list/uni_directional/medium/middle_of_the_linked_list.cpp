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

// My Approach
// Node *middleNode(Node *head)
// {
//     int length = 0, mid = 0, index = 1;
//     Node *temp = head;

//     while (temp != nullptr)
//     {
//         temp = temp->next;
//         length++;
//     }

//     mid = (length / 2) + 1;
//     temp = head;

//     while ((temp != nullptr) && (index < mid))
//     {
//         temp = temp->next;
//         index++;
//     }
//     return temp;
// }

// Optimal Approach
// Tortoise and Hare algorithm
Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while ((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 7};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    std::cout << "Middle of the Linked List is " << middleNode(head)->data << std::endl;
    return 0;
}

// https://leetcode.com/problems/middle-of-the-linked-list/submissions/2056733945/