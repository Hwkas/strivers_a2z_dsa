#include <iostream>

int largestElement(std::vector<int> &nums)
{
    int largest_element = INT_MIN;

    for (int i : nums)
    {
        if (i > largest_element)
        {
            largest_element = i;
        }
    }
    return largest_element;
}

int main()
{
    std::vector<int> v;
    v.push_back(3);
    v.push_back(3);
    v.push_back(6);
    v.push_back(1);

    std::cout << "ans: " << largestElement(v) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1