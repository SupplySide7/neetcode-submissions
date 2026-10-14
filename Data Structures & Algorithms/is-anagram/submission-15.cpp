class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}

        array<int, 26> char_histogram;
        for (const char &c : s) {
            ++char_histogram[c - 'a'];
        }

        for (const char &c : t) {
            --char_histogram[c - 'a'];
        }

        for (const int &i :char_histogram) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};
