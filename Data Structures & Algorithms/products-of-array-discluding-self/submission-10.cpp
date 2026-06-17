class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result(nums.size());
        size_t n = nums.size();
        vector<int> prefix_array(n);
        vector<int> suffix_array(n);
        prefix_array.at(0) = 1;
        suffix_array.at(n - 1) = 1;

        for (int i = 1; i < n; i++) {
            prefix_array.at(i) = nums.at(i - 1) * prefix_array.at(i - 1);
            suffix_array.at(n - 1 - i) = nums.at(n - i) * suffix_array.at(n - i);
            
        }
        for (int i = 0; i < n; i++) {
            result.at(i) = prefix_array.at(i) * suffix_array.at(i);
        }
        return result;
    }
};
