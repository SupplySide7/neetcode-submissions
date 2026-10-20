class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for (const int& num : nums) {
            seen.insert(num);
        }
        
        int n_max = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = 0;
            if (seen.contains(nums[i] - 1)) {continue;}
            n = 1;
            while (seen.contains(nums[i] + n)) {
                n++;
            }
            n_max = std::max(n_max, n);
        }
        return n_max;
    }
};
