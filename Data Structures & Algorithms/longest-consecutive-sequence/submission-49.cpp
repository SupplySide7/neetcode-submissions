class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());

        int max_n = 0;
        for (const int& num : nums) {
            if (nums_set.contains(num - 1)) {continue;}    
            int n = 1;
            while (nums_set.contains(num + n)) {
                n++;
            }
            max_n = std::max(n, max_n);
        }
        return max_n;
    }
};
