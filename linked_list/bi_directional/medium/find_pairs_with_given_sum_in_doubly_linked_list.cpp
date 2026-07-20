#include <iostream>

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node(
        int data_param,
        Node *previous_param = nullptr,
        Node *next_param = nullptr) : data(data_param), previous(previous_param), next(next_param) {}
};

Node *arrayToDoublyLinkedList(std::vector<int> &v)
{
    if (v.empty())
    {
        return nullptr;
    }

    Node *head = new Node(v[0]);
    Node *temp = head;
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(v[i], temp);
        temp = temp->next;
    }
    return head;
}

void traverseForward(Node *head)
{
    if (head != nullptr)
    {
        while (head != nullptr)
        {
            std::cout << head->data << ((head->next != nullptr) ? " -> " : "");
            head = head->next;
        }

        std::cout << std::endl;
    }
}

void print(const std::vector<std::pair<int, int>> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << "{" << arr[i].first << ", " << arr[i].second << "}" << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] " << std::endl;
}

std::vector<std::pair<int, int>> findPairs(Node *head, int k)
{
    Node *left = head, *right = head;
    std::vector<std::pair<int, int>> sum_pairs;

    while (right->next != nullptr)
    {
        right = right->next;
    }

    while (left->data < right->data)
    {
        if ((left->data + right->data) == k)
        {
            sum_pairs.push_back({left->data, right->data});
            left = left->next;
            right = right->previous;
        }
        else if ((left->data + right->data) > k)
        {
            right = right->previous;
        }
        else
        {
            left = left->next;
        }
    }
    return sum_pairs;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 9};
    Node *head = arrayToDoublyLinkedList(v);
    traverseForward(head);
    std::vector<std::pair<int, int>> sum_list = findPairs(head, 5);
    print(sum_list);
    return 0;
}

// https://www.naukri.com/code360/problems/find-pair-with-a-given-sum-in-a-doubly-linked-list_1164172