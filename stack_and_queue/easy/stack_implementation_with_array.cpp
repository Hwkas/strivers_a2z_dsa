#include <iostream>
#include <stdexcept>

class Stack
{
public:
    int index, size;
    int *arr;

    Stack(int size = 100) : size(size)
    {
        index = -1;
        arr = new int[size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool empty()
    {
        return (index == -1);
    }

    bool full()
    {
        return (index == (size - 1));
    }

    int top()
    {
        if (empty())
        {
            throw std::underflow_error("Stack underflow");
        }

        return arr[index];
    }

    void push(int val)
    {
        if (full())
        {
            throw std::overflow_error("Stack Overflow");
        }

        arr[++index] = val;
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Stack underflow");
        }

        index--;
    }
};

int main()
{
    Stack stk(5);

    std::cout << "stk.empty(): " << stk.empty() << std::endl;
    std::cout << "stk.full(): " << stk.full() << std::endl;

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    std::cout << "stk.top(): " << stk.top() << std::endl;

    // stk.push(6);

    stk.pop();
    stk.pop();

    std::cout << "stk.empty(): " << stk.empty() << std::endl;
    std::cout << "stk.full(): " << stk.full() << std::endl;
    std::cout << "stk.top(): " << stk.top() << std::endl;

    return 0;
}