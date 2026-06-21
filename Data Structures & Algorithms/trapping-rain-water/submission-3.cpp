class Solution {
public:
    int trap(vector<int>& height) {
        int max_left_height = 0;
        int max_right_height = 0;
        int total_water = 0;

        int left = 0;
        int right = static_cast<int>(height.size() - 1);
            
            while (left < right) {
                int left_height = height[left];
                int right_height = height[right];

                max_left_height = std::max(max_left_height, left_height);
                max_right_height = std::max(max_right_height, right_height);

                int water = 0;
                int water_level = 0;
                if (max_left_height < max_right_height) {
                    ++left;
                    water_level = max_left_height;
                    water = std::max(0, water_level - height[left]);
                }
                else {
                    --right;
                    water_level = max_right_height;
                    water = std::max(0, water_level - height[right]);
                }
            total_water += water;
            }
        return total_water;
    }
};
