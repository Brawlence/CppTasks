// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        
        int cheapest = prices[0];
        int profit = 0;
        
        for (auto &price : prices) {
            cheapest = std::min(cheapest, price);
            profit = std::max(price - cheapest, profit);           
        }
        
        return profit;
    }
};