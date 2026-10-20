class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (const int& num : nums) {
            ++freq[num];
        }
        vector<vector<int>> result(nums.size());
        for (auto [num, count] : freq) {
            result[count - 1].push_back(num);
        }
        vector<int> out;
        for (int i = ssize(result) - 1; i >= 0; --i) {
            for (const int& num : result[i]) {
                out.push_back(num);
                if (out.size() == k) {return out;}
            }
            
        }
        return {};
    }
};
