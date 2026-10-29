class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> key{0};
        for (const char c : s) {
            ++key[c - 'a'];
        }
        for (const char c : t) {
            --key[c - 'a'];
        }
        return key == array<int, 26>{0};
    }
};
