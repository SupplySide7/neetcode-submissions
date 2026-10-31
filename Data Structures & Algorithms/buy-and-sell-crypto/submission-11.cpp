class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = numeric_limits<int>::max();
        for (int l = 0, r = 0; r < prices.size(); ++r){
            if (prices[r] < prices[l]) l = r;
            else maxprofit = std::max(maxprofit, prices[r] - prices[l]);
        } return maxprofit;
    }
};
