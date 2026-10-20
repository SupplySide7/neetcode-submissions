class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;

        for (const int& num : nums) {
            seen.insert(num);
        }
        
        int n_max = 0;
        for (const int& s : seen) {
            int n = 0;
            if (seen.contains(s - 1)) {continue;}
            n = 1;
            while (seen.contains(s + n)) {
                n++;
            }
            n_max = std::max(n_max, n);
        }
        return n_max;
    }
};
