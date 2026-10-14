string anagram_key(const string &s) {
        array<char, 26> histogram{};
        for (const char& c : s) {
            ++histogram[c - 'a'];
        }
        return string(histogram.begin(), histogram.end());
    }

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_lists;

        for (const string& s : strs) {
            anagram_lists[anagram_key(s)].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto& [key, string_list] : anagram_lists) {
            result.push_back(std::move(string_list));
        }
        return result;
    }
};

