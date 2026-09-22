#include <iostream>

// My Solution
// class StockSpanner
// {
// public:
//     int index;
//     std::vector<int> v;
//     std::stack<int> s;

//     StockSpanner()
//     {
//         index = -1;
//     }

//     int next(int price)
//     {
//         index++;
//         v.push_back(price);

//         while ((!s.empty()) && (v[s.top()] <= price))
//         {
//             s.pop();
//         }

//         int span = index - (s.empty() ? -1 : s.top());

//         s.push(index);

//         return span;
//     }
// };

class StockSpanner
{
public:
    int index;
    std::stack<std::pair<int, int>> s;

    StockSpanner()
    {
        index = -1;
    }

    int next(int price)
    {
        index++;

        while ((!s.empty()) && (s.top().second <= price))
        {
            s.pop();
        }

        int span = index - (s.empty() ? -1 : s.top().first);

        s.push({index, price});

        return span;
    }
};

int main()
{
    StockSpanner s;
    std::vector<int> v = {100, 80, 60, 70, 60, 75, 85};

    std::cout << "[";

    for (const auto &i : v)
    {
        std::cout << s.next(i) << ", ";
    }

    std::cout << "]" << std::endl;

    return 0;
}

// https://leetcode.com/problems/online-stock-span/submissions/2149073486/