#include <iostream>

int countPrimeSetBits(int left, int right)
{
    int arr[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};

    int temp = 0;
    int set_bits_count = 0;
    int ans = 0;
    for (int i = left; i <= right; i++)
    {
        temp = i;
        set_bits_count = 0;
        while (temp > 0)
        {
            if (temp & 1)
            {
                set_bits_count++;
            }
            temp >>= 1;
        }
        ans += arr[set_bits_count];
    }
    return ans;
}

int main()
{
    std::cout << "ans: " << countPrimeSetBits(10, 15) << std::endl;
    return 0;
}

// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/?envType=problem-list-v2&envId=bit-manipulation