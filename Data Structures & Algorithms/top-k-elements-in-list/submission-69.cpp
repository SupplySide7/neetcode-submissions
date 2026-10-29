class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (const int num : nums) {
            ++hashmap[num];
        }
        const int n = static_cast<int>(nums.size()) + 1;
        vector<vector<int>> freq_array(n, vector<int>(0));
        
        for (const auto [key, freq] : hashmap) {
            freq_array[freq].push_back(key);            
        }
        int cnt = 0;
        vector<int> result;
        for (int i = freq_array.size() - 1; i >= 0; --i) {
            for (const int num : freq_array[i]) {
                result.push_back(num);
                if (++cnt; cnt == k) {return result;}
            }
        }
        return {};
    }
};
