#include <iostream>
#include <stdexcept>

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

class Queue
{
public:
    Node *head, *tail;

    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~Queue()
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
            throw std::underflow_error("Queue underflow");
        }

        return head->data;
    }

    void push(int data)
    {
        Node *new_node = new Node(data);

        if (tail == nullptr)
        {
            head = new_node;
        }
        else
        {
            tail->next = new_node;
        }
        tail = new_node;
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Queue underflow");
        }

        Node *node_to_delete = head;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete node_to_delete;
    }
};

int main()
{
    Queue q;

    // q.pop();

    std::cout << "q.empty(): " << q.empty() << std::endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << "q.top(): " << q.top() << std::endl;

    q.pop();
    q.pop();
    q.pop();

    std::cout << "q.empty(): " << q.empty() << std::endl;
    std::cout << "q.top(): " << q.top() << std::endl;

    return 0;
}