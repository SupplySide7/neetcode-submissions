class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();
        int c = 0, max = 0;
        unordered_set<int> hashmap(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (hashmap.contains(nums[i] - 1)) continue;
            c = 1;
            while (i < n && hashmap.contains(nums[i] + c)) ++c;
            max = std::max(max, c);
        } return max;
    }
};
