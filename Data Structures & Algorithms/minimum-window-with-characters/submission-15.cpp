class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> need {0};
        int missing = static_cast<int>(t.size());
        int sub_index = 0, len = 0, minlen = numeric_limits<int>::max();
        for (const char c : t) ++need[c];
        for (int l = 0, r = 0; r < static_cast<int>(s.size()); ++r) {
            if (need[s[r]] > 0) --missing;
            --need[s[r]];
            while (missing == 0) {
                if (len = r - l + 1; len < minlen) {sub_index = l; minlen = len;}
                char c = s[l++]; ++need[c];
                if (need[c] > 0 ) {++missing;}
            }
        } return len == 0? "" : s.substr(sub_index, minlen);
    }
};
