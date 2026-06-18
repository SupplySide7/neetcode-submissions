class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (auto outer = nums.begin(); outer != std::prev(nums.end()); outer++) {
            
            /* sorted ascending order, so no negative numbers in the input set */
            if (*outer > 0) {break;}
            
            /* check for duplicate sets */
            if(outer > nums.begin() && *outer == *(std::prev(outer))) {continue;} 
            
            auto left = std::next(outer);
            auto right = std::prev(nums.end());

            while (left < right) {                
                int sum = *outer + *left + *right;
                
                if (sum == 0) {
                    result.push_back(vector<int>{*outer, *left, *right});
                    ++left;
                    --right;
                    
                    /* prevent processing a duplicate triplet */
                    while (left < right && (*left == *(std::prev(left)))) {
                        ++left;
                    }
                }
                else if (sum > 0) {
                    --right;
                }
                else {
                    ++left;
                }
            }
        }
        return result;
    }
};