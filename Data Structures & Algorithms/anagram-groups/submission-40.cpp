class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        vector<string>string_list;

        
        for (const string& strng : strs) {
            string key(26, 0);
            for (const char& c : strng) {
                ++key[c - 'a'];
            }
            table[key].push_back(strng);
        }

        vector<vector<string>> result;
        for (auto [key, string_list] : table) {
            result.push_back(string_list);
        }
        return result;
    }
};
