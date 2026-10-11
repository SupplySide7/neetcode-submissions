class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> seen;

        for (int j = 0; j < nums.size(); j++) {
            int needed = target - nums[j];
            int i;
            if (auto it = seen.find(needed); it != seen.end()) {
                i = it->second;
                return result = {i, j};
            } else {
                seen.insert({nums[j], j});
            }
        }
        return {};
    }
};