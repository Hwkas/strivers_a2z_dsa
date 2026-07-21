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
void reverse(Node *current)
{
    Node *before = nullptr, *after = nullptr;

    while (current != nullptr)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
    }
}

Node *reverseKGroup(Node *head, int k)
{
    Node *last_tail = nullptr, *next_head = nullptr, *current_head = head, *current = head;
    int count = 1;

    while (current != nullptr)
    {
        count++;
        current = current->next;

        if ((count == k) && (current != nullptr))
        {
            next_head = current->next;
            current->next = nullptr;
            reverse(current_head);
            current_head->next = next_head;

            if (last_tail != nullptr)
            {
                last_tail->next = current;
            }
            else
            {
                head = current;
            }

            last_tail = current_head;
            current = next_head;
            current_head = next_head;
            count = 1;
        }
    }

    return head;
}

// Striver's Solution
// Node *getKthNode(Node *curr, int k)
// {
//     while (curr && k > 0)
//     {
//         curr = curr->next;
//         k--;
//     }
//     return curr;
// }

// Node *reverseKGroup(Node *head, int k)
// {
//     // Creating a dummy node to handle edge cases easily
//     Node *dummy = new Node(0);
//     dummy->next = head;

//     // Pointer to keep track of the previous group's tail
//     Node *groupPrev = dummy;

//     while (true)
//     {
//         // Finding the k-th node from the groupPrev
//         Node *kth = getKthNode(groupPrev, k);
//         if (!kth)
//             break;

//         // Store the next group's head
//         Node *groupNext = kth->next;

//         // Break the chain to reverse current k-group cleanly
//         Node *prev = groupNext;
//         Node *curr = groupPrev->next;

//         // Reversing k nodes
//         for (int i = 0; i < k; i++)
//         {
//             Node *temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;
//         }

//         // Connecting previous group to the reversed group
//         Node *temp = groupPrev->next;
//         groupPrev->next = kth;
//         groupPrev = temp;
//     }

//     // Returning the new head
//     return dummy->next;
// }

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    head = reverseKGroup(head, 5);
    traverseLinkedList(head);
    return 0;
}

// https://leetcode.com/problems/reverse-nodes-in-k-group/description/