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

Node *detectCycle(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main()
{
    std::vector<int> v = {2, 5, 8, 7};
    Node *head = arrayToLinkedList(v);
    // traverseLinkedList(head);
    head->next->next->next->next = head->next;
    Node *cycle_start = detectCycle(head);
    std::cout << "Linked List Cycle: " << ((cycle_start != nullptr) ? cycle_start->data : NULL) << std::endl;
    return 0;
}

// https://leetcode.com/problems/linked-list-cycle-ii/