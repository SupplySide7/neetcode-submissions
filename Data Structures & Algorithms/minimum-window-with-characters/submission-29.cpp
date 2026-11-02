class Solution {
public:
    string minWindow(string s, string t) {
        const int m = static_cast<int>(t.size()), n = static_cast<int>(s.size());
        int missing = m, best_l = 0, minlen = numeric_limits<int>::max();
        array<int, 128> need{};
        for (const char c : t) ++need[c];
        for (int l = 0, r = 0; r < n; ++r) {
            if (need[s[r]] > 0) --missing;
            --need[s[r]];
            while (missing == 0) {
                if (r - l + 1 < minlen) {minlen = r - l + 1; best_l = l;}
                char c = s[l++]; ++need[c];
                if (need[c] > 0) ++missing;
            }
        } return minlen == numeric_limits<int>::max()? "" : s.substr(best_l, minlen);
    }
};
