#include <iostream>

// // Approach 1
// class MyQueue
// {
// public:
//     std::stack<int> s1, s2;

//     MyQueue() {}

//     void push(int x)
//     {
//         while (s1.size())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }

//         s1.push(x);

//         while (s2.size())
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int pop()
//     {
//         int temp = s1.top();
//         s1.pop();
//         return temp;
//     }

//     int peek()
//     {
//         return s1.top();
//     }

//     bool empty()
//     {
//         return s1.empty();
//     }
// };

// Approach 2
class MyQueue
{
public:
    std::stack<int> input, output;

    MyQueue() {}

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty())
        {
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        if (output.empty())
        {
            return -1;
        }

        return output.top();
    }

    bool empty()
    {
        return (input.empty() && output.empty());
    }
};

// https://leetcode.com/problems/implement-queue-using-stacks/description/