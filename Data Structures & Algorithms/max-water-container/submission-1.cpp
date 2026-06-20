class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int left = 0;
        size_t right = heights.size() - 1;
        int left_height = heights[left];
        int right_height = heights[right];

        while (left < right) {
            int area = std::min(left_height, right_height) * ((int)right - left);
            max_area = max(max_area, area);

            
            if ((left < right) && left_height < right_height) {
                ++left;
                left_height = heights[left];
            }
            else if ((left < right) && left_height > right_height) {
                --right;
                right_height = heights[right];
            }
            else {
                /* left and right bars are the same height */
                while (left < right && (left_height == right_height)) {
                    if (heights[left + 1] > heights[left]) {
                        ++left;
                        left_height = heights[left];
                    }
                    else if (heights[right - 1] > heights[right]) {
                        --right;
                        right_height = heights[right];
                    }
                    else if (heights[right - 1] > heights[left + 1]) {
                        --right;
                        right_height = heights[right];
                    }
                    else {++left;
                        left_height = heights[left];
                    }
                }
            }
        }
        return max_area;
    }
};