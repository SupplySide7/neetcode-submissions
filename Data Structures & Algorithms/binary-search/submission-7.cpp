class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int n = static_cast<int>(nums.size());
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo)/2;
            if (nums[mid] >= target) {hi = mid;} // mid is true: answer is mid or left of mid
            else {lo = mid + 1;} // mid is false: answer is right of in
        }
        // if all values are less than target, then lo is 1 past end and lo == n
        // target may not exist at all, first position of nums[mid] >= target is the target or where it 
        // would go if it were in the array
        return (lo < n) && (nums[lo] == target) ? lo: -1;
    }
};
