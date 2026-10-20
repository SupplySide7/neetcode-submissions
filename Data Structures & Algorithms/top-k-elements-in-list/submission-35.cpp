class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (const int& num : nums) {
            ++freq_map[num];
        }
        vector<vector<int>> freq_array(static_cast<int>(nums.size()));
        for (const auto& [key, freq] : freq_map) {
            freq_array[freq - 1].push_back(key);    
        }
        vector<int> result;
        int n = 0;
        for (int i = freq_array.size() - 1; i >= 0; --i) {
            for (const int& num : freq_array[i]) {
                result.push_back(num);
                if (n++; n == k) {
                    return result;
                }
            }
        }
        return {};
    }
};
