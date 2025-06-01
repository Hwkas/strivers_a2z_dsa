#include <iostream>

void selectionSort(std::vector<int> &nums)
{
    int size = nums.size();
    int index;

    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] < nums[index])
            {
                index = j;
            }
        }
        std::swap(nums[i], nums[index]);
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

    selectionSort(nums);

    std::cout << "ans: ";
    print(nums);
    return 0;
}

// https://www.naukri.com/code360/problems/selection-sort_981162