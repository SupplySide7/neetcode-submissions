class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int needed = 0;
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            needed = target - nums[i];
            if(seen.contains(needed)) { 
                return {seen.at(needed), i};
            }
            else {
                seen.insert({nums[i], i});
            }
        }
    }
};
