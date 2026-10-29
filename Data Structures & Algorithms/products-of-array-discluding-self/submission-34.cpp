class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        const int n = static_cast<int>(nums.size());
        vector<int> product(n, 1);
        for (int i = 0; i < n; ++i) {
            product[i] *= left;
            left *= nums[i];
            
        }
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            product[i] *= right;
            right *= nums[i];
        }
        return product;
    }
};
