class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;

        while (left < right) {
            int area = std::min(heights[left], heights[right]) * (right - left);
            max_area = max(max_area, area);

            if ((left < right) && heights[left] <= heights[right]) {
                ++left;
            }
            else if ((left < right) && heights[left] > heights[right]) {
                --right;
            }
        }
        return max_area;
    }
};