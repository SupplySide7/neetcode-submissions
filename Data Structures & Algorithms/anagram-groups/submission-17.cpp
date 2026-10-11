class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagram_array;
        unordered_map<string, vector<string>> anagram_map;

        for (auto& s : strs) {
            string key(26, 0);
            for (char ch : s) {
                key[ch - 'a']++;
            }
            anagram_map[key].push_back(s);
        }
        for (const auto& [key, group] : anagram_map) {
            anagram_array.push_back(group);
        }
    return anagram_array;
    }
};