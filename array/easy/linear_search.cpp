#include <iostream>

int search(std::vector<int> &arr, int x)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(12);

    std::cout << "ans: " << search(v, 12) << std::endl;
    return 0;
}

// https://leetcode.com/problems/move-zeroes/description/