class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hashmap;
        for (const string& str : strs) {
            string key(26, 0);
            for (const char& c : str) {
                ++key[c - 'a'];
            } hashmap[key].push_back(str);
        }
        for (auto [key, strs] : hashmap) {
            vector<string> string_list;
            for (const string& str : strs) {
                string_list.push_back(str);
            } result.push_back(string_list);
        } return result;
    }
};
