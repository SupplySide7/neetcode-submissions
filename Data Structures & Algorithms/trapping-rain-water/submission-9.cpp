class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, l = 0, r = static_cast<int>(height.size()) - 1;
        int left_max = 0, right_max = 0;
        while (l < r) {
            left_max = std::max(left_max, height[l]);
            right_max = std::max(right_max, height[r]);
            if (left_max > right_max) {water += right_max - height[r]; --r;}
            else {water += left_max - height[l]; ++l;}
        }
        return water;
    }
};
