class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> seen;

        for (int j = 0; j < nums.size(); j++) {
            
            if (auto it = seen.find(target - nums[j]); it != seen.end()) {
                return result = {it->second, j};
            } else {
                seen.insert({nums[j], j});
            }
        }
        return {};
    }
};