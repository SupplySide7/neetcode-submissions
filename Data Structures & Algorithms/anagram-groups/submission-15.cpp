class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_map;

        for (auto& s : strs) {
            string key(26, 0);
            for (char ch : s) {
                key[ch - 'a']++;
            }
            anagram_map[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& [key, group] : anagram_map) {
            result.push_back(group);
        }
    return result;
    }
};