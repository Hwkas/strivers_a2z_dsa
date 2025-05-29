#include <iostream>
#include <map>

// using ordered map
// std::vector<int> getFrequencies(std::vector<int> &v)
// {
//     std::map<int, int> map;

//     int size = v.size();

//     for (int i = 0; i < size; i++)
//     {
//         map[v[i]]++;
//     }

//     std::pair<int, int> highest = {0, INT_MIN}, lowest = {0, INT_MAX};

//     for (auto i : map)
//     {
//         if (i.second > highest.second)
//         {
//             highest.first = i.first;
//             highest.second = i.second;
//         }
//         if (i.second < lowest.second)
//         {
//             lowest.first = i.first;
//             lowest.second = i.second;
//         }
//     }
//     return {highest.first, lowest.first};
// }

// using un-ordered map, Optimal approach
std::vector<int> getFrequencies(std::vector<int> &v)
{
    std::unordered_map<int, int> map;

    int size = v.size();

    for (int i = 0; i < size; i++)
    {
        map[v[i]]++;
    }

    std::pair<int, int> highest = {0, INT_MIN}, lowest = {0, INT_MAX};

    for (auto i : map)
    {
        if ((i.second > highest.second) || (i.second == highest.second && i.first < highest.first))
        {
            highest.first = i.first;
            highest.second = i.second;
        }
        if ((i.second < lowest.second) || (i.second == lowest.second && i.first < lowest.first))
        {
            lowest.first = i.first;
            lowest.second = i.second;
        }
    }
    return {highest.first, lowest.first};
}

void print(std::vector<int> arr)
{
    int size = arr.size();
    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] ";
}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(4);
    print(getFrequencies(v));
    return 0;
}

// https://www.naukri.com/code360/problems/k-most-occurrent-numbers_625382