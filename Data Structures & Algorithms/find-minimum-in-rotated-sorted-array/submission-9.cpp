class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;
        int min_element;

        while (left < right) {
            int midpoint = left + (right - left)/2;

            if (nums[midpoint] > nums[right]) { // min_element in the right section
                left = midpoint + 1;
            }
            else { // min_element in the left section
                right = midpoint;
            }
        }
        return nums[left];
    }
};
