#include <iostream>
#include <map>

// int majorityElement(std::vector<int> &nums)
// {
//     std::unordered_map<int, int> map;

//     for (auto i : nums)
//     {
//         map[i]++;
//     }

//     int size = nums.size();

//     for (auto i : map)
//     {
//         if (i.second > (size / 2))
//         {
//             return i.first;
//         }
//     }
//     return -1;
// }

int majorityElement(std::vector<int> &nums)
{
    /*
        The Moore Voting Algorithm (also called Boyer-Moore Majority Vote Algorithm)
        is used to find the majority element in an array.
        The majority element is the one that appears more than n/2 times, where n is the size of the array.

        🔍 Key Idea:
        If there is a majority element, it will remain after canceling out different elements.
    */
    int count = 0, element = 0;

    for (auto i : nums)
    {
        if (count == 0)
        {
            element = i;
            count++;
        }
        else if (i == element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return element;
}

int main()
{
    std::vector<int> v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(5);

    std::cout << "ans: " << majorityElement(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/majority-element/description/