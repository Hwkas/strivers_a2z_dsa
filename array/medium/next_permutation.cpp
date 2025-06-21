#include <iostream>

void nextPermutation(std::vector<int> &nums)
{
    int size = nums.size();
    int index = -1;

    for (int i = (size - 1); i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            index = i - 1;
            break;
        }
    }

    if (index == -1)
    {
        std::reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = (size - 1); i > index; i--)
    {
        if (nums[i] > nums[index])
        {
            std::swap(nums[i], nums[index]);
            break;
        }
    }

    std::reverse((nums.begin() + index + 1), nums.end());
}

void print(std::vector<int> &arr)
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
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);

    nextPermutation(v);

    std::cout << "ans: ";
    print(v);
    return 0;
}

// https://leetcode.com/problems/next-permutation/description/