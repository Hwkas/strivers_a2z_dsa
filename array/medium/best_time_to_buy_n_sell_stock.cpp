#include <iostream>

int maxProfit(std::vector<int> &prices)
{
    int max_profit = 0, buy_price = INT_MAX;

    for (auto i : prices)
    {
        buy_price = std::min(buy_price, i);
        max_profit = std::max(max_profit, (i - buy_price));
    }
    return max_profit;
}

int main()
{
    std::vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);

    std::cout << "ans: " << maxProfit(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/