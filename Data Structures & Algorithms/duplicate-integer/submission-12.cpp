class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        return nums.size() == seen.size()? false : true;
    }
};