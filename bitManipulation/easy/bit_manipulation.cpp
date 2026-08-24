#include <iostream>

std::vector<int> bitManipulation(int num, int i)
{
    return {
        (num & (1 << (i - 1)) ? true : false), // Get the bit value at the "i"th position of "num"
        num | (1 << (i - 1)),                  // Set the bit at the "i"th position of "num"
        num & ~(1 << (i - 1))};                // Clear the bit at the "i"th position of "num"
}

int main()
{
    std::vector<int> ans = bitManipulation(11, 2);
    std::cout << ans[0] << " " << ans[1] << " " << ans[2] << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/bit-manipulation_8142533?leftPanelTabValue=PROBLEM