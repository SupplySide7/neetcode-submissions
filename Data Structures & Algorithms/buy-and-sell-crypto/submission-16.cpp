class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = static_cast<int>(prices.size());
        int maxprofit = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            if (prices[r] < prices[l]) l = r;
            else {maxprofit = std::max(maxprofit, prices[r] - prices[l]);}
        } return maxprofit;
    }
};
