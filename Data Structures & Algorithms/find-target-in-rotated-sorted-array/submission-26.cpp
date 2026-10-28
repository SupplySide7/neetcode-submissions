class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = static_cast<int>(nums.size());
        const int last = nums.back();
        const auto key = [&] (const int x) {return pair(x <= last, x);};
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (key(nums[mid]) >= key(target)) {hi = mid;}
            else {lo = mid + 1;}
        }
        return (lo < n) && nums[lo] == target? lo : -1;
    }
};
