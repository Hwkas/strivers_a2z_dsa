#include <iostream>

void insertionSort(std::vector<int> &nums)
{
    int size = nums.size();

    for (int i = 1; i <= size - 1; i++)
    {
        for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--)
        {
            std::swap(nums[j - 1], nums[j]);
        }
    }
}

void print(std::vector<int> arr)
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
    std::vector<int> nums;
    nums.push_back(13);
    nums.push_back(46);
    nums.push_back(24);
    nums.push_back(52);
    nums.push_back(20);
    nums.push_back(9);

    insertionSort(nums);

    std::cout << "ans: ";
    print(nums);
    return 0;
}

// https://www.geeksforgeeks.org/problems/insertion-sort/1