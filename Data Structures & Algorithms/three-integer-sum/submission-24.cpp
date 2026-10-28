class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = static_cast<int>(nums.size()) - 1;
        ranges::sort(nums.begin(), nums.end());
        vector<vector<int>> result = {};
        for (int i = 0; i < n - 1; ++i) {
            int l = i + 1, r = n;
            if (nums[i] > 0) break; // no sum = 0 exists
            if (i > 0 && nums[i] == nums[i - 1]) continue; // avoid duplicates
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {--r;}
                else if (sum < 0) {++l;}
                else {
                    result.push_back({nums[i], nums[l], nums[r]});
                    ++l; --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                }
            }
        } return result;
    }
};
