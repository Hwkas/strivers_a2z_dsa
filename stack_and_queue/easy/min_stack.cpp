#include <iostream>

// Approach 1
// class MinStack
// {
// public:
//     std::stack<std::pair<int, int>> s;

//     MinStack() {}

//     void push(int value)
//     {
//         if (s.empty())
//         {
//             s.push({value, value});
//         }
//         else
//         {
//             s.push({value, std::min(s.top().second, value)});
//         }
//     }

//     void pop()
//     {
//         s.pop();
//     }

//     int top()
//     {
//         return s.top().first;
//     }

//     int getMin()
//     {
//         return s.top().second;
//     }
// };

// Approach 2
class MinStack
{
public:
    long long min;
    std::stack<long long> s;

    MinStack() {}

    void push(long long value)
    {
        if (s.empty())
        {
            min = value;
            s.push(value);
            return;
        }

        if (value > min)
        {
            s.push(value);
        }
        else
        {
            s.push(2 * value - min);
            min = value;
        }
    }

    void pop()
    {
        if (s.empty())
        {
            return;
        }

        long long x = s.top();
        s.pop();

        if (x < min)
        {
            min = 2 * min - x;
        }
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }

        long long x = s.top();

        if (min < x)
        {
            return x;
        }

        return min;
    }

    int getMin()
    {
        return min;
    }
};
