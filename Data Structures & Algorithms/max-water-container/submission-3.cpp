class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int left = 0;
        size_t right = heights.size() - 1;

        while (left < right) {
            int area = std::min(heights[left], heights[right]) * ((int)right - left);
            max_area = max(max_area, area);

            
            if ((left < right) && heights[left] < heights[right]) {
                ++left;
            }
            else if ((left < right) && heights[left] > heights[right]) {
                --right;
            }
            else {
                /* left and right bars are the same height */
                while (left < right && (heights[left] == heights[right])) {
                    if (heights[left + 1] > heights[left]) {
                        ++left;
                    }
                    else if (heights[right - 1] > heights[right]) {
                        --right;
                    }
                    else if (heights[right - 1] > heights[left + 1]) {
                        --right;
                    }
                    else {++left;}
                }
            }
        }
        return max_area;
    }
};