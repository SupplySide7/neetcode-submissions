class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_lists;

        for (const auto& s : strs) {
            string histogram(26, 0);
            for (const char &c : s) {
                histogram[c - 'a']++;
            }
            anagram_lists[histogram].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& [key, string_list] : anagram_lists) {
            result.push_back(std::move(string_list));
        }
    return result;
    }
};