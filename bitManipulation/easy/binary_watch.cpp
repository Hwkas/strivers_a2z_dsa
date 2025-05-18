#include <iostream>

int no_of_set_bits(int n)
{
    int temp = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            temp++;
        }
        n >>= 1;
    }
    return temp;
}

std::vector<std::string> readBinaryWatch(int turnedOn)
{
    int set_bits_map[60] = {0};
    for (int i = 0; i < 60; i++)
    {
        set_bits_map[i] = no_of_set_bits(i);
    }

    std::vector<std::string> ans;
    std::string str_time = "";
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (set_bits_map[i] + set_bits_map[j] == turnedOn)
            {
                str_time = std::to_string(i) + ":" + (j < 10 ? "0" + std::to_string(j) : std::to_string(j));
                ans.push_back(str_time);
            }
        }
    }
    return ans;
}

void print(std::vector<std::string> v)
{
    std::cout << "[";
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << v[n - 1] << "]" << std::endl;
}

int main()
{
    std::vector<std::string> ans = readBinaryWatch(1);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/binary-watch/submissions/1474853408/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY