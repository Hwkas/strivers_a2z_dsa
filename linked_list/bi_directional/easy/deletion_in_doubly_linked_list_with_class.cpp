#include <iostream>

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node(int data_param, Node *previous_param = nullptr, Node *next_param = nullptr)
        : data(data_param), previous(previous_param), next(next_param) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

    void clear()
    {
        while (this->head != nullptr)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        this->tail = nullptr;
    }

public:
    DoublyLinkedList(Node *head = nullptr, Node *tail = nullptr)
        : head(head), tail(tail) {}

    ~DoublyLinkedList()
    {
        clear();
    }

    void arrayToDoublyLinkedList(std::vector<int> &v)
    {
        clear();

        if (v.empty())
        {
            return;
        }

        this->head = new Node(v[0]);
        Node *temp = head;
        int n = v.size();

        for (int i = 1; i < n; i++)
        {
            temp->next = new Node(v[i], temp);
            temp = temp->next;
        }

        this->tail = temp;
    }

    void traverseForward()
    {
        Node *temp = this->head;
        while (temp != nullptr)
        {
            std::cout << temp->data << ((temp->next != nullptr) ? " -> " : "");
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void traverseBackward()
    {
        Node *temp = this->tail;
        while (temp != nullptr)
        {
            std::cout << temp->data << ((temp->previous != nullptr) ? " -> " : "");
            temp = temp->previous;
        }
        std::cout << std::endl;
    }

    void deleteHead()
    {
        if (this->head == nullptr)
        {
            return;
        }

        if (this->head->next == nullptr)
        {
            clear();
            return;
        }

        Node *temp = this->head;
        this->head = this->head->next;
        this->head->previous = nullptr;
        delete temp;
    }
};

int main()
{
    std::vector<int> v = {}; //{2, 5, 8, 7};
    DoublyLinkedList dll;
    dll.arrayToDoublyLinkedList(v);
    dll.traverseForward();
    dll.traverseBackward();
    dll.deleteHead();
    dll.traverseForward();
    dll.traverseBackward();
    return 0;
}