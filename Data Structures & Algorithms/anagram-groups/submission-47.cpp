class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for (const string& s : strs) {
            string key(26, 0);
            for (const char c : s) {
                ++key[c - 'a'];
            }
            hashmap[key].push_back(s); 
        }
        vector<vector<string>> result;
        for (auto [key, strings] : hashmap) {
            result.push_back(strings);
        }
        return result;
    }
};
