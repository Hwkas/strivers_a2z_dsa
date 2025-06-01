#include <iostream>

void bubbleSort(std::vector<int> &nums, int size)
{
    if (size == 1)
    {
        return;
    }

    for (int j = 0; j < size - 1; j++)
    {
        if (nums[j] > nums[j + 1])
        {
            std::swap(nums[j], nums[j + 1]);
        }
    }
    bubbleSort(nums, --size);
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

    bubbleSort(nums, nums.size());

    std::cout << "ans: ";
    print(nums);
    return 0;
}

// https://www.geeksforgeeks.org/problems/bubble-sort/1