class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int max_sell = prices[0];
        int profit = 0;
        int max_profit = 0;

        for (int i = 0; i != prices.size(); i++) {
            min_buy = std::min(min_buy, prices[i]);
            profit = std::max(0, prices[i] - min_buy);
            max_profit = std::max(max_profit, profit);
        }
        return max_profit;
    }
};