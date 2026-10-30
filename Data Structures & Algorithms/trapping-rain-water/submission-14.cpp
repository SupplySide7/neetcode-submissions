class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, l = 0, r = height.size() - 1;
        int leftmax = height[l], rightmax = height[r];
        while (l < r) {
            if (leftmax < rightmax) {
                water += leftmax - height[l];
                ++l;
                leftmax = std::max(leftmax, height[l]);
            } else {
                water += rightmax - height[r];
                --r;
                rightmax = std::max(rightmax, height[r]);
            }
        } return water;
    }
};
