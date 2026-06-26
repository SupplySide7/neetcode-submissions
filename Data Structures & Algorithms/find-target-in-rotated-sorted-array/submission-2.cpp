class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;
        int midpoint;

        while (left < right) {
            midpoint = left + (right - left)/2;

            if (nums[midpoint] > nums[right]) { // min element in the right section
                left = midpoint + 1;
            }
            else { // min_element in the left section
                right = midpoint;
            }
        }

        if (target >= nums[left] && target <= nums[n - 1]) {
            right = n - 1;            
        } else {
            right = left - 1;
            left = 0;
        }

        while (left <= right) {
            midpoint = left + ((right - left)/2);
            if (target == nums[midpoint]) {
                return midpoint;
            }
            else if (target > nums[midpoint]) {
                left = midpoint + 1;
            }
            else {
                right = midpoint - 1;
            }
        }
        return -1;   
    }
};
