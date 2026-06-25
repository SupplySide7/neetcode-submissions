class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;
        int min_element;

        int left_prev;
        int right_prev;

        while (left <= right) {

            if (nums[left] < nums[right]) { // already sorted window
                min_element = std::min(min_element, nums[left]);
                break;
            }

            int midpoint = left + (right - left)/2;
            min_element = std::min(min_element, nums[midpoint]);

            if (nums[left] <= nums[midpoint]) {
                left = midpoint + 1;
            }
            else {
                right = midpoint - 1;
            }
        }
        return min_element;
    }
};
