class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}

        array<int, 26> char_histogram;
        for (int i = 0; i < s.size(); ++i) {
            ++char_histogram[s[i] - 'a'];
            --char_histogram[t[i] - 'a'];
        }

        for (const int &i :char_histogram) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};
