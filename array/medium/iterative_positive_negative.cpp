#include <iostream>

// my solution
// void rearrangeArray(std::vector<int> &nums)
// {
//     int positive_count = 0, negative_count = 0, positive_index = 0, negative_index = 1, size = nums.size();
//     std::vector<int> ans(size);

//     for (auto i : nums)
//     {
//         (i >= 0) ? positive_count++ : negative_count++;
//     }

//     if (positive_count == 0 && negative_index == 1)
//     {
//         negative_index = 0;
//     }

//     for (int i = 0; i < size; i++)
//     {
//         if (nums[i] >= 0)
//         {
//             ans[positive_index] = nums[i];
//             positive_index += (positive_index < ((negative_count * 2) - 1)) ? 2 : 1;
//         }
//         else
//         {
//             ans[negative_index] = nums[i];
//             negative_index += (negative_index < ((positive_count * 2) - 2)) ? 2 : 1;
//         }
//     }
//     nums = ans;
// }

// strivers solution
void rearrangeArray(std::vector<int> &nums)
{
    int i = 0, j = 0, positive_size = 0, negative_size = 0;
    std::vector<int> positive_nums;
    std::vector<int> negative_nums;

    for (auto i : nums)
    {
        if (i >= 0)
        {
            positive_nums.push_back(i);
        }
        else
        {
            negative_nums.push_back(i);
        }
    }

    positive_size = positive_nums.size();
    negative_size = negative_nums.size();

    j = std::min(positive_size, negative_size);

    for (; i < j; i++)
    {
        nums[i * 2] = positive_nums[i];
        nums[(i * 2) + 1] = negative_nums[i];
    }

    i *= 2;

    while (j < positive_size)
    {
        nums[i++] = positive_nums[j++];
    }
    while (j < negative_size)
    {
        nums[i++] = negative_nums[j++];
    }
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
    v.push_back(-5);
    v.push_back(-2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
    v.push_back(1);
    v.push_back(8);
    v.push_back(0);
    v.push_back(-8);

    rearrangeArray(v);

    std::cout << "ans: ";
    print(v);
    return 0;
}

// https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1&selectedLang=python3