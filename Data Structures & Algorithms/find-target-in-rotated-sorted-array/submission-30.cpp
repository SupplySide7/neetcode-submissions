class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int last = nums.back();
        int lo = 0, n = static_cast<int>(nums.size()), hi = n;
        auto num = [&] (const int x) {return std::pair(x <= last, x);};
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (num(nums[mid]) >= num(target)) {hi = mid;}
            else {lo = mid + 1;}
        } return lo < n && nums[lo] == target? lo : -1;
    }
};
