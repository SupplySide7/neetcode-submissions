class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        std::unordered_multimap<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            seen.emplace(nums[i], i);
        }

        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];
            int j;
            if (auto it = seen.find(needed); it != seen.end()) {
                if (j = (*it).second; i != j) {return result = {i, j};}
            }
            
        }
    }
};
