class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int l = 0, r = 0; r < prices.size(); ++r) {
            if (prices[r] < prices[l]) l = r;
            int profit = prices[r] - prices[l];
            maxprofit = std::max(maxprofit, profit);
        } return maxprofit;
    }
};
