class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = numeric_limits<int>::max();
        for (int l = 0, r = 0; r < prices.size(); ++r){
            maxprofit = std::max(maxprofit, prices[r] - prices[l]);
            if (prices[r] < prices[l]) l = r;
        } return maxprofit;
    }
};
