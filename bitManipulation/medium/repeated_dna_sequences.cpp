#include <iostream>

std::vector<std::string> findRepeatedDnaSequences(std::string s)
{
    std::unordered_map<int, int> m;
    std::vector<std::string> r;
    int size = s.size();

    for (int t = 0, i = 0; i < size; i++)
        if (m[t = ((t << 3) & 0x3FFFFFFF) | (s[i] & 7)]++ == 1)
            r.push_back(s.substr(i - 9, 10));
    return r;
    // std::vector<std::string> repated_sequences;
    // std::unordered_map<int, int> map;
    // int t = 0, i = 0, ss = s.size();
    // /*
    //     Filling the first 9*3 digits of t.
    // */
    // while (i < 9)
    //     t = (t << 3) | (s[i++] & 7);
    // while (i < ss)
    //     /*
    //         using 0x3FFFFFFF as it's binary representation is 00111111111111111111111111111111
    //         & we are filling 30 bits of t, that is the case.

    //         (t << 3) & 0x3FFFFFFF) to unset 31 & 32 binary digits,
    //         while preserving all the set bits till 30th digit.
    //     */
    //     if (map[t = ((t << 3) & 0x3FFFFFFF) | (s[i++] & 7)]++ == 1)
    //         repated_sequences.push_back(s.substr(i - 10, 10));
    // return repated_sequences;
}

void print(std::vector<std::string> v)
{
    std::cout << "[";
    int n = v.size();
    for (int i = 0; i < n; i++)
    {

        std::cout << v[i] << ((i != (n - 1)) ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<std::string> ans = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    print(ans);
    return 0;
}

// https://leetcode.com/problems/repeated-dna-sequences/solutions/53877/i-did-it-in-10-lines-of-c/