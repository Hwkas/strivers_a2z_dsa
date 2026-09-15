#include <iostream>

// My Solution
// std::vector<int> asteroidCollision(std::vector<int> &asteroids)
// {
//     std::stack<int> s;

//     for (const auto &i : asteroids)
//     {
//         if (i > 0)
//         {
//             s.push(i);
//         }
//         else
//         {
//             while ((!s.empty()) && (s.top() > 0) && (s.top() < std::abs(i)))
//             {
//                 s.pop();
//             }

//             if (s.empty() || (s.top() < 0))
//             {
//                 s.push(i);
//             }
//             else if (s.top() == std::abs(i))
//             {
//                 s.pop();
//             }
//         }
//     }

//     std::vector<int> result(s.size());
//     int j = (s.size() - 1);

//     while (!s.empty())
//     {
//         result[j--] = s.top();
//         s.pop();
//     }

//     return result;
// }

// Striver's
std::vector<int> asteroidCollision(std::vector<int> &asteroids)
{
    std::vector<int> s;

    for (const auto &i : asteroids)
    {
        if (i > 0)
        {
            s.push_back(i);
        }
        else
        {
            while ((!s.empty()) && (s.back() > 0) && (s.back() < std::abs(i)))
            {
                s.pop_back();
            }

            if (s.empty() || (s.back() < 0))
            {
                s.push_back(i);
            }
            else if (s.back() == std::abs(i))
            {
                s.pop_back();
            }
        }
    }

    return s;
}

void print(std::vector<int> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] " << std::endl;
}

int main()
{
    std::vector<int> asteroids = {5, 10, -5};
    std::vector<int> result = asteroidCollision(asteroids);
    print(result);

    return 0;
}

// https://leetcode.com/problems/asteroid-collision/description/