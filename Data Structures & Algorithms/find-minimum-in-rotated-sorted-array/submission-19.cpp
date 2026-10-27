class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0;
        int hi = static_cast<int>(nums.size() - 1);
        int last = nums.back();

        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (nums[mid] < last) {hi = mid;}
            else {lo = mid + 1;}
        }
        return nums[lo];
    }
};
