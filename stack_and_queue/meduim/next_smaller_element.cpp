#include <iostream>

std::vector<int> nextSmallerElement(std::vector<int> &arr, int n)
{
    std::vector<int> result(n);
    std::stack<int> s;

    for (int i = (n - 1); i >= 0; i--)
    {
        while ((!s.empty()) && (arr[i] <= s.top()))
        {
            s.pop();
        }

        result[i] = (s.empty() ? -1 : s.top());
        s.push(arr[i]);
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
    std::vector<int> nums = {2, 1, 4, 3};

    std::vector<int> result = nextSmallerElement(nums, nums.size());

    print(result);

    return 0;
}

// https://www.naukri.com/code360/problems/next-smaller-element_1112581?leftPanelTabValue=PROBLEM