class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 128> need {0};
        int missing = static_cast<int>(t.size());
        int sub_index = 0, len = 0, minlen = numeric_limits<int>::max();
        for (const char c : t) {
            ++need[c];
        }
        for (int l = 0, r = 0; r < static_cast<int>(s.size()); ++r) {
            if (need[s[r]] > 0) --missing;
            --need[s[r]];
            while (missing == 0) {
                len = r - l + 1;
                if (len < minlen) {sub_index = l; minlen = len;}
                ++need[s[l]];
                if (need[s[l]] > 0 ) {++missing;} ++l;
            }
        } return len == 0? "" : s.substr(sub_index, minlen);
    }
};
