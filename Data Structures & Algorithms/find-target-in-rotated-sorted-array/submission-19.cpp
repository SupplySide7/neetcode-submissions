class Solution {
public:
    int search(vector<int>& nums, int target) {
        int last = nums.back();
        auto key = [last] (int x) {return std::pair(x <= last, x);};
        int n = static_cast<int>(nums.size());
        int lo = 0;
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (key(nums[mid]) >= key(target)) {hi = mid;}
            else {lo = mid + 1;}
        }
        return lo < n && nums[lo] == target ? lo : -1;
    }
};
