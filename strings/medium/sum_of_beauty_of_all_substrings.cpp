#include <iostream>

// Brute Force Solution
int beautySum(std::string s)
{
    std::unordered_map<char, int> freqs;
    int n = s.size(), sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            freqs[s[j]]++;

            int max = INT_MIN, min = INT_MAX;
            for (const auto &fq : freqs)
            {
                max = std::max(max, fq.second);
                min = std::min(min, fq.second);
            }
            sum += (max - min);
        }
        freqs.clear();
    }
    return sum;
}

// Gemini Optimization
int beautySum(std::string s)
{
    int n = s.size();
    int total_beauty = 0;

    for (int i = 0; i < n; i++)
    {
        int freqs[26] = {0};

        for (int j = i; j < n; j++)
        {
            freqs[s[j] - 'a']++;

            int max_freq = 0;
            int min_freq = INT_MAX;

            for (int k = 0; k < 26; k++)
            {
                if (freqs[k] > 0)
                {
                    max_freq = std::max(max_freq, freqs[k]);
                    min_freq = std::min(min_freq, freqs[k]);
                }
            }

            total_beauty += (max_freq - min_freq);
        }
    }
    return total_beauty;
}

int main()
{
    std::string s = "aabcbaa";
    std::cout << "Sum of Beauty of All Substrings is " << beautySum(s) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/submissions/2019365298/