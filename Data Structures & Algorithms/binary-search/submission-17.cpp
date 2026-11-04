class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int lo = 0, hi = n;
        while (lo < hi) {
            int median = lo + (hi - lo)/2;
            if (nums[median] >= target) hi = median;
            else lo = median + 1;
        }
        return lo < n && nums[lo] == target? lo : -1;
    }
};
