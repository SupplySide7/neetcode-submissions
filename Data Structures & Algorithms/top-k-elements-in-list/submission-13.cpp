class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        for (const int& num : nums) {
            ++freq[num];
        }
        
        vector<vector<int>> freq_array(nums.size());
        for (const auto& [num, count] : freq) {
            freq_array[count - 1].push_back(num);
        }

        vector<int> result;
        result.reserve(k);
        for (int i = ssize(freq_array) - 1; i >= 0; i--) {
            int j = 0;
            for (int num : freq_array[i]) {
                result.push_back(num);
                if (ssize(result) == k) {return result;}
            }
        }
        return result;
    }
};
