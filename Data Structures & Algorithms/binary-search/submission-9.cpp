class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int n = static_cast<int>(nums.size());
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (nums[mid] >= target) {hi = mid;}
            else {lo = mid + 1;}
        }
        return (lo < n && nums[lo] == target)? lo : -1;
    }
};
