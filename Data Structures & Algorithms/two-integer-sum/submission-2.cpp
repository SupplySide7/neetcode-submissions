class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int needed = 0;
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            needed = target - nums[i];
            auto it = seen.find(needed);
            if(it != seen.end()) { 
                return {it->second, i};
            }
            else {
                seen.insert({nums[i], i});
            }
        }
    }
};
