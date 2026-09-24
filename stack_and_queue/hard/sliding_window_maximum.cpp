#include <iostream>

std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
{
    std::deque<int> dq;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        while ((!dq.empty()) && (nums[dq.back()] <= nums[i]))
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= (k - 1))
        {
            if (dq.front() <= (i - k))
            {
                dq.pop_front();
            }
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
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
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    std::vector<int> result = maxSlidingWindow(nums, 3);
    print(result);
    return 0;
}

// https://leetcode.com/problems/sliding-window-maximum/