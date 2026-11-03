class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> idx;
        const int n = heights.size(); int max_area = 0;
        for (int i = 0; i <= n; ++i) {
            int curr_h = (i == n)? 0 : heights[i];
            while (!idx.empty() && curr_h < heights[idx.back()]) {
                int prev_h = heights[idx.back()];
                idx.pop_back();
                int left = idx.empty()? -1 : idx.back();
                int area = (i - left - 1) * prev_h;
                max_area = std::max(max_area, area);
            } idx.push_back(i);
        } return max_area;
    }
};
