class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> string_map;

        for (const string& s : strs) {
            string key(26, 0);
            for (const char& c : s) {
                ++key[c - 'a'];
            }
            string_map[key].push_back(s);
        }

        for (const auto& [key, strings] : string_map) {
            result.push_back(strings);
        }
        return result;
    }
};
