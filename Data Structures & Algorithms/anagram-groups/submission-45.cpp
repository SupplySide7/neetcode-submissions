class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;
        
        for (const string& s : strs) {
            string key(26,0);
            for (const char& c : s) {
                ++key[c - 'a'];
            }
            anagram_map[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& [key, string_list] : anagram_map) {
            result.push_back(string_list);
        }
        return result;
    }
};
