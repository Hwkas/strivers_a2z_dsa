#include <iostream>
#include <stdexcept>

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

class Stack
{
public:
    Node *head;

    Stack()
    {
        head = nullptr;
    }

    ~Stack()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool empty()
    {
        return (head == nullptr);
    }

    int top()
    {
        if (empty())
        {
            throw std::underflow_error("Stack underflow");
        }

        return head->data;
    }

    void push(int data)
    {
        head = new Node(data, head);
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Stack underflow");
        }

        Node *node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }
};

int main()
{
    Stack stk;

    // stk.pop();

    std::cout << "stk.empty(): " << stk.empty() << std::endl;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    std::cout << "stk.top(): " << stk.top() << std::endl;

    stk.pop();
    stk.pop();
    stk.pop();

    std::cout << "stk.empty(): " << stk.empty() << std::endl;
    std::cout << "stk.top(): " << stk.top() << std::endl;

    return 0;
}