class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int median = left + ((right - left)/2);
            if (target == nums[median]) {
                return median;
            }
            else if (target > nums[median]) {
                left = median + 1;
            }
            else {
                right = median - 1;
            }
        }
        return -1;
    }
};