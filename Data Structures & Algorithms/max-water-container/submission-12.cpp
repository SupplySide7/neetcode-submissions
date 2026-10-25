class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int l = 0;
        int r = static_cast<int>(heights.size()) - 1;

        while (l < r) {
            const int height = std::min(heights[l], heights[r]);
            const int area = height * (r - l);
            max_area = std::max(max_area, area);
            if (heights[l] < heights[r]) {++l;}
            else {--r;}
        }
        return max_area;
    }
};
