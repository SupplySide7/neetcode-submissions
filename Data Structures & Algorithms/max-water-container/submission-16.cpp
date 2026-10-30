class Solution {
public:
    int maxArea(vector<int>& heights) {
        int water = 0, max_water = 0, l = 0, r = heights.size() - 1;
        while (l < r) {
            int height = std::min(heights[l], heights[r]);
            water = height * (r - l);
            max_water = std::max(water, max_water);
            if (heights[l] < heights[r]) ++l;
            else --r;
        } return max_water;
    }
};
