class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = static_cast<int>(prices.size());
        int maxprofit = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            int profit = prices[r] - prices[l];
            maxprofit = std::max(maxprofit, profit);
            if (prices[r] < prices[l]) l = r;
        } return maxprofit;
    }
};
