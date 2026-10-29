class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> seen(nums.begin(), nums.end());
        const int set_size = seen.size();
        return n == set_size? false : true;
    }
};