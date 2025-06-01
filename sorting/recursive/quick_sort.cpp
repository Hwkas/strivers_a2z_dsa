#include <iostream>

int partition(std::vector<int> &nums, int start, int end)
{
    int pivot = nums[start];
    int i = start;
    int j = end;

    while (i < j)
    {
        while (nums[i] <= pivot && i <= end - 1)
        {
            i++;
        }

        while (nums[j] > pivot && j >= start + 1)
        {
            j--;
        }
        if (i < j)
            std::swap(nums[i], nums[j]);
    }
    std::swap(nums[start], nums[j]);
    return j;
}

void quickSort(std::vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pIndex = partition(nums, start, end);
    quickSort(nums, start, pIndex - 1);
    quickSort(nums, pIndex + 1, end);
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

    quickSort(nums, 0, nums.size() - 1);

    std::cout << "ans: ";
    print(nums);
    return 0;
}

// https://www.geeksforgeeks.org/problems/quick-sort/1