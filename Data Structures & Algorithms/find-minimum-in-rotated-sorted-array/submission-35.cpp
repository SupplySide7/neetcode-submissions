class Solution {
public:
    int findMin(vector<int> &nums) {
        const int last = nums.back();
        int lo = 0, n = nums.size(), hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (nums[mid] <= last) hi = mid;
            else lo = mid + 1;
        } return nums[lo];
    }
};
