#include <iostream>

std::vector<int> arrayLeaders(std::vector<int> &arr)
{
    int size = arr.size();
    int current_max = INT_MIN;
    std::vector<int> ans;

    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] >= current_max)
        {
            ans.push_back(arr[i]);
            current_max = arr[i];
        }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
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
    // v.push_back(4);
    // v.push_back(7);
    // v.push_back(1);
    // v.push_back(0);

    v.push_back(10);
    v.push_back(22);
    v.push_back(12);
    v.push_back(3);
    v.push_back(0);
    v.push_back(6);

    std::vector<int> ans = arrayLeaders(v);
    std::cout << "ans: ";
    print(ans);
    return 0;
}

// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1