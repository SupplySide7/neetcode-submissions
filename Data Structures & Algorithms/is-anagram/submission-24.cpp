class Solution {
public:
    bool isAnagram(string s, string t) {
        string key(26, 0);
        for (const char c : s) {
            ++key[c - 'a'];
        }
        for (const char c : t) {
            --key[c - 'a'];
        }
        return ranges::all_of(key, [] (const char c) {return c == 0;});
    }
};
