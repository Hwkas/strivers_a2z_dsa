#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

int main()
{
    Node *x = new Node(1, nullptr);
    Node *y = new Node(2);

    std::cout << "x->data: " << x->data << " - x->next: " << x->next << std::endl;
    std::cout << "y->data: " << y->data << " - y->next: " << y->next << std::endl;
    return 0;
}