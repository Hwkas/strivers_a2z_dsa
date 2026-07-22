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

// Node *reverse(Node *head)
// {
//     Node *before = nullptr, *after = nullptr, *current = head;

//     while (current != nullptr)
//     {
//         after = current->next;
//         current->next = before;
//         before = current;
//         current = after;
//     }
//     return before;
// }

// Node *addOne(Node *head)
// {
//     if (head == nullptr)
//     {
//         return new Node(1);
//     }

//     head = reverse(head);

//     Node *temp = head;
//     int digit_to_add = 1;

//     while (temp != nullptr)
//     {
//         if ((temp->data + digit_to_add) < 10)
//         {
//             temp->data = temp->data + digit_to_add;
//             digit_to_add = 0;
//             break;
//         }
//         else
//         {
//             temp->data = 0;
//             digit_to_add = 1;
//         }
//         temp = temp->next;
//     }

//     head = reverse(head);

//     if (digit_to_add)
//     {
//         head = new Node(1, head);
//     }
//     return head;
// }

// Striver's Solution
int addHelper(Node *temp)
{
    if (temp == nullptr)
    {
        return 1;
    }

    int carry = addHelper(temp->next);

    temp->data += carry;

    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}

// My Solution
void doIncrement(Node *head)
{
    if (head->next == nullptr)
    {
        head->data = head->data + 1;
        return;
    }

    doIncrement(head->next);
    if (head->next->data == 10)
    {
        head->next->data = 0;
        head->data = head->data + 1;
    }
}

Node *addOne(Node *head)
{
    if (head == nullptr)
    {
        return new Node(1);
    }

    doIncrement(head);

    if (head->data == 10)
    {
        head->data = 0;
        head = new Node(1, head);
    }
    return head;
}

int main()
{
    std::vector<int> v = {9, 9};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    head = addOne(head);
    traverseLinkedList(head);
    return 0;
}

// https://www.naukri.com/code360/problems/add-one-to-a-number-represented-as-linked-list_920557