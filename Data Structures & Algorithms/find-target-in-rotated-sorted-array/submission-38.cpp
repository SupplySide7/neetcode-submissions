class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int last = nums.back();
        const auto key = [&] (const int x) {return std::pair(x <= last, x);};
        int lo = 0, n = nums.size(), hi = n;
        while (lo < hi) {
            int med = lo + (hi - lo)/2;
            if (key(nums[med]) >= key(target)) hi = med;
            else lo = med + 1;
        }
        return lo < n && nums[lo] == target? lo : -1;
    }
};
