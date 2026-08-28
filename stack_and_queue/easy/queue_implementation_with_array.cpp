#include <iostream>
#include <stdexcept>

class Queue
{
public:
    int start, end, curr_size, max_size;
    int *arr;

    Queue(int size) : max_size(size)
    {
        start = -1;
        end = -1;
        curr_size = 0;
        arr = new int[size];
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool empty()
    {
        return !curr_size;
    }

    bool full()
    {
        return (curr_size == max_size);
    }

    int top()
    {
        if (empty())
        {
            throw std::underflow_error("Queue underflow");
        }

        return arr[start];
    }

    void push(int val)
    {
        if (full())
        {
            throw std::overflow_error("Queue Overflow");
        }

        if (start == -1)
        {
            start = 0;
        }

        end = (end + 1) % max_size;
        arr[end] = val;
        curr_size++;
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Queue underflow");
        }

        start = (start + 1) % max_size;
        curr_size--;
    }
};

int main()
{
    Queue q(5);

    std::cout << "q.empty(): " << q.empty() << std::endl;
    std::cout << "q.full(): " << q.full() << std::endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << "q.top(): " << q.top() << std::endl;

    // q.push(6);

    q.pop();
    q.pop();

    std::cout << "q.empty(): " << q.empty() << std::endl;
    std::cout << "q.full(): " << q.full() << std::endl;
    std::cout << "q.top(): " << q.top() << std::endl;

    return 0;
}