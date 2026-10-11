class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto& s : strs) {
            string key(26, 0);
            for (char c : s) key[c - 'a']++;
            groups[key].push_back(s);
        }

        vector<vector<string>> out;
        for (auto& [key, g] : groups) out.push_back(std::move(g));    // std:: avoids a Clang warning
// simpler O(k log k) key: string key = s; ranges::sort(key);
    return out;
    }
};