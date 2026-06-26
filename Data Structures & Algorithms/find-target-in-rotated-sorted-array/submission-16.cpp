class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int midpoint = left + (right - left)/2;

            if (target == nums[midpoint]) {
                return midpoint;
            }
            else if (nums[left] <= nums[midpoint]) { //left side cleanly sorted
                
                if (target <= nums[midpoint] && target >= nums[left]) { // its in here
                    right = midpoint - 1;
                }
                else { //(target > nums[midpoint])
                    left = midpoint + 1;
                }
            }
            else { //right side cleanly sorted
                
                if (target > nums[midpoint] && target <= nums[right]) {
                    left = midpoint + 1;
                }
                else right = midpoint - 1;
            }
        }
        return -1;   
    }
};
