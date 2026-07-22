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
// Node *addTwoNumbers(Node *l1, Node *l2)
// {
//     Node *l3_head = new Node(-1);
//     Node *l3_tail = l3_head;
//     int carry = 0;

//     while ((l1 != nullptr) && (l2 != nullptr))
//     {
//         if ((l1->data + l2->data + carry) < 10)
//         {
//             l3_tail->next = new Node(l1->data + l2->data + carry);
//             carry = 0;
//         }
//         else
//         {
//             l3_tail->next = new Node((l1->data + l2->data + carry) % 10);
//             carry = (l1->data + l2->data + carry) / 10;
//         }
//         l1 = l1->next;
//         l2 = l2->next;
//         l3_tail = l3_tail->next;
//     }

//     while (l1 != nullptr)
//     {
//         if ((l1->data + carry) < 10)
//         {
//             l3_tail->next = new Node(l1->data + carry);
//             carry = 0;
//         }
//         else
//         {
//             l3_tail->next = new Node((l1->data + carry) % 10);
//             carry = (l1->data + carry) / 10;
//         }
//         l1 = l1->next;
//         l3_tail = l3_tail->next;
//     }

//     while (l2 != nullptr)
//     {
//         if ((l2->data + carry) < 10)
//         {
//             l3_tail->next = new Node(l2->data + carry);
//             carry = 0;
//         }
//         else
//         {
//             l3_tail->next = new Node((l2->data + carry) % 10);
//             carry = (l2->data + carry) / 10;
//         }
//         l2 = l2->next;
//         l3_tail = l3_tail->next;
//     }

//     if (carry)
//     {
//         l3_tail->next = new Node(carry);
//     }
//     return l3_head->next;
// }

// Striver's Solution
Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    int carry = 0;
    while ((l1 != NULL || l2 != NULL) || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{
    std::vector<int> v1 = {9, 9};
    std::vector<int> v2 = {8, 8};
    Node *head1 = arrayToLinkedList(v1);
    Node *head2 = arrayToLinkedList(v2);
    Node *head = addTwoNumbers(head1, head2);
    traverseLinkedList(head);
    return 0;
}

// https://leetcode.com/problems/add-two-numbers/