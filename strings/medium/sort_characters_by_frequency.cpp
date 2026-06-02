#include <iostream>
#include <map>

// My Solution
// std::string frequencySort(std::string s)
// {
//     std::map<char, int> freq;
//     std::string freq_sort_s;

//     for (const auto &i : s)
//     {
//         freq[i]++;
//     }

//     while (!freq.empty())
//     {
//         int max = INT_MIN;
//         char c;
//         for (const auto &i : freq)
//         {
//             if (i.second > max)
//             {
//                 max = i.second;
//                 c = i.first;
//             }
//         }
//         freq_sort_s += std::string(freq[c], c);
//         freq.erase(c);
//     }
//     return freq_sort_s;
// }

// std::string frequencySort(std::string s)
// {
//     int freq[128] = {0};

//     for (auto &c : s)
//     {
//         freq[c]++;
//     }

//     auto compare = [&](char a, char b)
//     {
//         if (freq[a] != freq[b])
//         {
//             return freq[a] > freq[b];
//         }
//         return a < b;
//     };

//     std::sort(s.begin(), s.end(), compare);
//     return s;
// }

// std::string frequencySort(std::string s)
// {
//     std::unordered_map<char, int> freq_map;

//     for (auto &c : s)
//     {
//         freq_map[c]++;
//     }

//     std::vector<std::pair<char, int>> freq_v;

//     for (const auto &i : freq_map)
//     {
//         freq_v.push_back(i);
//     }

//     int freq[128] = {0};

//     auto compare = [&](std::pair<char, int> &a, std::pair<char, int> &b)
//     {
//         return a.second > b.second;
//     };

//     std::sort(freq_v.begin(), freq_v.end(), compare);

//     std::string ans = "";

//     for (auto [c, f] : freq_v)
//     {
//         ans.append(f, c);
//     }
//     return ans;
// }

// striver's Optimal Solution
std::string frequencySort(std::string s)
{
    std::pair<char, int> freq[128];

    for (int i = 0; i < 128; i++)
    {
        freq[i] = {i + '\0', 0};
    }

    for (const auto &c : s)
    {
        freq[c].second++;
    }

    auto compare = [&](std::pair<char, int> &a, std::pair<char, int> &b)
    {
        return a.second > b.second;
    };

    std::sort(freq, freq + 128, compare);

    std::string ans = "";
    ans.reserve(s.length());

    for (auto [c, f] : freq)
    {
        if (f == 0)
        {
            break;
        }
        ans.append(f, c);
    }
    return ans;
}

int main()
{
    std::string s = "2a554442f544asfasssffffasss";
    // "tree";
    std::cout << "Frequency Sorted String '" << frequencySort(s) << "'." << std::endl;
    return 0;
}

// https://leetcode.com/problems/sort-characters-by-frequency/description/