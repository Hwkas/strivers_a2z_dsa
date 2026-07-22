#include <iostream>
#include <set>

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

// Node *getIntersectionNode(Node *headA, Node *headB)
// {
//     std::set<Node *> st;

//     while (headA != nullptr)
//     {
//         st.insert(headA);
//         headA = headA->next;
//     }

//     while (headB != nullptr)
//     {
//         if (st.find(headB) != st.end())
//         {
//             return headB;
//         }
//         headB = headB->next;
//     }
//     return nullptr;
// }

// My Solution
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

// Node *getIntersectionNode(Node *headA, Node *headB)
// {
//     Node *original_headA = headA;
//     headA = reverse(headA);

//     original_headA->next = headB;

//     Node *slow = headA, *fast = headA, *intersection = nullptr;

//     while ((fast != nullptr) && (fast->next != nullptr))
//     {
//         slow = slow->next;
//         fast = fast->next->next;

//         if (slow == fast)
//         {
//             slow = headA;
//             while (slow != fast)
//             {
//                 slow = slow->next;
//                 fast = fast->next;
//             }
//             intersection = slow;
//             break;
//         }
//     }

//     original_headA->next = nullptr;
//     reverse(headA);
//     return intersection;
// }

// Stiver's Solution
// int findLength(Node *head)
// {
//     int length = 0;
//     Node *temp = head;

//     while (temp != nullptr)
//     {
//         temp = temp->next;
//         length++;
//     }
//     return length;
// }

// Node *findIntersection(Node *longLL, Node *shortLL, int offset)
// {
//     for (int i = 0; i < offset; i++)
//     {
//         longLL = longLL->next;
//     }

//     while (longLL != shortLL)
//     {
//         longLL = longLL->next;
//         shortLL = shortLL->next;
//     }
//     return longLL;
// }

// Node *getIntersectionNode(Node *headA, Node *headB)
// {
//     int lengthA = findLength(headA), lengthB = findLength(headB);
//     int offset = std::abs(lengthA - lengthB);
//     return (lengthA > lengthB) ? findIntersection(headA, headB, offset) : findIntersection(headB, headA, offset);
// }

Node *getIntersectionNode(Node *headA, Node *headB)
{
    if ((headA == nullptr) || (headB == nullptr))
    {
        return nullptr;
    }

    Node *tempA = headA, *tempB = headB;

    while (tempA != tempB)
    {
        tempA = (tempA == nullptr) ? headB : tempA->next;
        tempB = (tempB == nullptr) ? headA : tempB->next;
    }
    return tempA;
}

int main()
{
    return 0;
}

// https://leetcode.com/problems/intersection-of-two-linked-lists/description/