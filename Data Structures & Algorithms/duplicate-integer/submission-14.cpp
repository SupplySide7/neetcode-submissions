class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        seen.reserve(nums.size());
        for (const int num : nums) {
            if (auto [it, inserted] = seen.insert(num); !inserted) return true;
        }
        return false;
    }
};