#include <iostream>

bool arraySortedOrNot(std::vector<int> &arr)
{
    int size = arr.size();

    for (int i = 0; i < size - 1; i++)
    {
        // For Ascending Order
        if (arr[i] > arr[i + 1])
        // For Descending Order
        // if (arr[i] < arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    std::cout << "ans: " << (arraySortedOrNot(v) ? "True" : "False") << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/check-if-an-array-is-sorted0701/1