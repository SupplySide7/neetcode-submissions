class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq_map;
        const int n = nums.size();
        vector<vector<int>> freq_array(n + 1, vector<int>());
        vector<int> result;
        for (const int& num : nums) {
            ++freq_map[num];
        }
        for (auto& [num, freq] : freq_map) {
            freq_array[freq].push_back(num);
        }
        for (int i = n; i >= 0; --i) {
            for (const auto& num : freq_array[i]) {
                result.push_back(num);
                if (--k; k == 0) return result;
            }
        } return {};
    }
};
