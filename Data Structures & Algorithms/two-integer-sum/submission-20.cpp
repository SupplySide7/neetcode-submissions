class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            int needed = target - nums[i];

            if (auto it = seen.find(needed) ; it != seen.end()) {
                result = {it->second, i};
                return result;
            } else {
                seen.insert({nums[i], i});
            }
        }
    }
};
