class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0, l = 0, r = static_cast<int>(heights.size()) - 1;
        
        while (l < r) {
            const int height = std::min(heights[l], heights[r]);
            max_area = std::max(max_area, height * (r - l));
            if (heights[l] < heights[r]) ++l;
            else --r;
        }
        return max_area;
    }
};
