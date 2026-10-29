class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int needed = target - nums[i];
            if (auto it = seen.find(needed); it != seen.end()) {
                return {it->second, i};
            } else {seen.insert({nums[i], i});}
        
        } return {};
    }
};
