class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int max_n = 0;  
        for (int i = 0; i < nums.size(); ++i) {
            if (seen.contains(nums[i] - 1)) continue;
            int n = 1;
            while (seen.contains(nums[i] + n)) ++n;
            max_n = std::max(max_n, n);
        } return max_n;
    }
};
