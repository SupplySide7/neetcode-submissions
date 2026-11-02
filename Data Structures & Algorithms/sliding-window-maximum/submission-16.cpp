class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> maxlist;
        for (int r = 0; r < static_cast<int>(nums.size()); ++r) {
            while (!window.empty() && nums[r] > nums[window.back()]) window.pop_back();
            window.push_back(r);
            if (window.front() == r - k) window.pop_front();
            if (r >= k - 1) maxlist.push_back(nums[window.front()]);
        }
        return maxlist;
    }
};
