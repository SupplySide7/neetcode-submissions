class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int max_n = 0;
        int n = 0;
        for (const int num : seen) {
            if (seen.contains(num - 1)) {continue;}
            n = 1;
            while (seen.contains(num + n)) {
                n++;
            }
            max_n = std::max(n, max_n);
        }
        return max_n;
    }
};
