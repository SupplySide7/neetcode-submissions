class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result = {};
        const int n = static_cast<int>(nums.size());
        result.reserve(n - k + 1);
        deque<int> window;
        for (int r = 0; r < static_cast<int>(nums.size()); ++r) {
            while (!window.empty() && nums[r] >= nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(r);
            if (window.front() == r - k) window.pop_front();
            if (r >= k - 1) result.push_back(nums[window.front()]);

        } return result;
    }
};
