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

Node *sortList(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    Node *zeros_head = new Node(-1), *ones_head = new Node(-1), *twos_head = new Node(-1);
    Node *zeros_tail = zeros_head, *ones_tail = ones_head, *twos_tail = twos_head;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zeros_tail->next = temp;
            zeros_tail = temp;
        }
        else if (temp->data == 1)
        {
            ones_tail->next = temp;
            ones_tail = temp;
        }
        else
        {
            twos_tail->next = temp;
            twos_tail = temp;
        }
        temp = temp->next;
    }

    twos_tail->next = nullptr;
    ones_tail->next = twos_head->next;
    zeros_tail->next = ones_head->next;
    head = zeros_head->next;

    delete zeros_head;
    delete ones_head;
    delete twos_head;
    return head;
}

int main()
{
    std::vector<int> v = {1, 0, 2, 1, 0, 2, 1};
    Node *head = arrayToLinkedList(v);
    traverseLinkedList(head);
    head = sortList(head);
    traverseLinkedList(head);
    return 0;
}

// https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937


/*
 * DRY RUN — sortList (Dutch National Flag style, 0/1/2 partition)
 * =================================================================
 *
 * CASE 1: All three buckets non-empty
 * ------------------------------------
 * Input: head -> 2 -> 0 -> 1 -> 0 -> 2 -> nullptr
 * Label nodes by position: A(2) -> B(0) -> C(1) -> D(0) -> E(2) -> nullptr
 *
 * While loop walks the list once, bucketing by value:
 *   A(2) -> twos
 *   B(0) -> zeros
 *   C(1) -> ones
 *   D(0) -> zeros
 *   E(2) -> twos
 *
 * State after the loop (dummy heads omitted for brevity):
 *   zeros: B -> D          (zeros_tail = D, D->next still stale = A)
 *   ones:  C                (ones_tail  = C, C->next still stale = D)
 *   twos:  A -> E           (twos_tail  = E, E->next still nullptr, orig. tail)
 *
 * Relinking, executed back-to-front (twos, then ones, then zeros):
 *
 *   (1) twos_tail->next = nullptr;
 *       twos_tail = E  =>  E->next = nullptr
 *       twos chain: A -> E -> nullptr   [DONE, terminated]
 *
 *   (2) ones_tail->next = twos_head->next;
 *       ones_tail = C, twos_head->next = A  =>  C->next = A
 *       ones chain: C -> A -> E -> nullptr   [DONE, flows into twos]
 *
 *   (3) zeros_tail->next = ones_head->next;
 *       zeros_tail = D, ones_head->next = C (untouched by step 2,
 *       since step 2 only wrote C->next, not ones_head->next itself)
 *       => D->next = C
 *       zeros chain: D -> C -> A -> E -> nullptr   [DONE, flows into ones]
 *
 *   head = zeros_head->next = B
 *
 * Final: B(0) -> D(0) -> C(1) -> A(2) -> E(2) -> nullptr
 *      = 0 -> 0 -> 1 -> 2 -> 2   ✓ correctly sorted
 *
 *
 * CASE 2: Middle bucket (ones) is empty — the tricky case
 * ---------------------------------------------------------
 * Input: head -> 0 -> 0 -> 2 -> 2 -> nullptr
 * Label: B(0) -> D(0) -> A(2) -> E(2) -> nullptr
 *
 * After the loop:
 *   zeros: B -> D          (zeros_tail = D)
 *   ones:  <empty>          (ones_tail == ones_head, ones_head->next == nullptr)
 *   twos:  A -> E           (twos_tail = E)
 *
 * Relinking:
 *
 *   (1) twos_tail->next = nullptr;
 *       E->next = nullptr
 *       twos chain: A -> E -> nullptr
 *
 *   (2) ones_tail->next = twos_head->next;
 *       ones_tail IS ones_head (bucket was empty!)
 *       twos_head->next = A
 *       => ones_head->next = A
 *       This is the key step: it PATCHES the empty ones dummy to point
 *       straight at the twos list, instead of leaving it as nullptr.
 *
 *   (3) zeros_tail->next = ones_head->next;
 *       zeros_tail = D
 *       ones_head->next = A   <-- reads the value JUST patched in step (2)
 *       => D->next = A
 *       zeros chain: D -> A -> E -> nullptr
 *
 *   head = zeros_head->next = B
 *
 * Final: B(0) -> D(0) -> A(2) -> E(2) -> nullptr
 *      = 0 -> 0 -> 2 -> 2   ✓ correctly sorted, twos NOT lost
 *
 *
 * WHY THE ORDER MATTERS
 * -----------------------
 * Relinking goes twos -> ones -> zeros (back-to-front) so that each
 * step reads a dummy's ->next only AFTER any possible patch to it has
 * already happened. If zeros were relinked first (reading ones_head->next
 * before it's patched), an empty ones bucket would incorrectly link
 * zeros straight to nullptr, silently dropping (leaking) the twos list.
 */