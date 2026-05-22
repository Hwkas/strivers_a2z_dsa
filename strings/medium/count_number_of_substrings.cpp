#include <iostream>

int atMostKDistinct(std::string s, int k)
{
    int left = 0, res = 0;
    std::unordered_map<char, int> freq;

    for (int right = 0; right < s.size(); right++)
    {
        freq[s[right]]++;

        while (freq.size() > k)
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }
        res += (right - left + 1);
    }
    return res;
}

int countSubstrings(std::string s, int k)
{
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main()
{
    std::string s = "abcbaa";
    // "pqpqs";
    int k = 3;
    std::cout << "Number of substrings that contain exactly " << k << " distinct characters is " << countSubstrings(s, k) << "." << std::endl;
    return 0;
}

// https://takeuforward.org/data-structure/count-number-of-substrings