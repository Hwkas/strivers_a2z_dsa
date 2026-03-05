#include <iostream>
#include <map>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> map;
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {
            return {map[target - nums[i]], i};
        }
        map[nums[i]] = i;
    }
    return {};
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
    v.push_back(2);
    v.push_back(7);
    v.push_back(12);
    v.push_back(15);

    std::vector<int> ans = twoSum(v, 9);
    std::cout << "ans: ";
    print(ans);
    return 0;
}

// https://leetcode.com/problems/two-sum/