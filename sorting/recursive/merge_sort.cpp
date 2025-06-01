#include <iostream>

void merge(std::vector<int> &nums, int start, int mid, int end)
{
    std::vector<int> temp;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else
        {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(nums[i++]);
    }

    while (j <= end)
    {
        temp.push_back(nums[j++]);
    }

    for (int k = start; k <= end; k++)
    {
        nums[k] = temp[k - start];
    }
}

void mergeSort(std::vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
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

    mergeSort(nums, 0, nums.size() - 1);

    std::cout << "ans: ";
    print(nums);
    return 0;
}

// https://www.geeksforgeeks.org/problems/merge-sort/1