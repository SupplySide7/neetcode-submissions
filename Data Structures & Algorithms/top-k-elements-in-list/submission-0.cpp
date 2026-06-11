class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash_map;
        vector<vector<int>> bucketArray(nums.size() + 1);
        vector<int> result;

        for (int &num : nums) {
            hash_map[num]++;
        }

        for (pair<const int, int> &entry : hash_map) {
            bucketArray[entry.second].push_back(entry.first); 
        }
        for (int j = bucketArray.size() - 1; j > 0; j--) {
            for (int n : bucketArray[j]) {result.push_back(n);}
            if (result.size() == k) {return result;}
        }
        return result;
    }
};
