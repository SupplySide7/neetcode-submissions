class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int m = static_cast<int>(s1.size()), n = static_cast<int>(s2.size());
        array<int, 26> need {}, have {};
        for (const char c : s1) ++need[c - 'a'];
        for (int l = 0, r = 0; r < n; ++r ) {
            ++have[s2[r] - 'a'];
            if (r - l + 1 == m) {
                if (have == need) return true;
                --have[s2[l++] - 'a'];
            }
        } return false;
    }
};
