class Solution {
public:
    int findMin(vector<int> &nums) {
        const int last = nums.back();
        int lo = 0, n = nums.size(), hi = n;
        while (lo < hi) {
            int med = lo + (hi - lo)/2;
            if (nums[med] <= last) hi = med;
            else lo = med + 1;
        } return nums[lo];
    }
};
