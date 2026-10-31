class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = numeric_limits<int>::max();
        const int n = prices.size();
        for (int l = 0, r = 0; r < n; ++r){
            maxprofit = std::max(maxprofit, prices[r] - prices[l]);
            if (prices[r] < prices[l]) l = r;
        } return maxprofit;
    }
};
